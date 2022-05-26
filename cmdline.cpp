//----------------------------------------------------------
// Project : clbase-c++
// Compile Code : gcc cmdline.cpp -lstdc++ -o out
//----------------------------------------------------------


// Header Files
//----------------------------------------------------------
#include <iostream>
#include <unistd.h>
#include <string.h>
//----------------------------------------------------------


// Function Prototype
//----------------------------------------------------------
char * cmdlineArg(int,char **);
//----------------------------------------------------------


// Main Code
//----------------------------------------------------------
int main(int argc, char** argv)
{

// Commandline Parsing
//----------------------------------------------------------
char * cmdArg = NULL;
cmdArg = cmdlineArg(argc,argv);
std::cout << "Argument Provided : " << cmdArg << std::endl;
//----------------------------------------------------------

return 0;
}
//----------------------------------------------------------


// Function Definition
//----------------------------------------------------------
char * cmdlineArg(int ac,char ** ag)
{
char sw;
char *arg = NULL;

    // Retrieve the (non-option) argument:
    if ( (ac <= 1) || (ag[ac-1] == NULL) || (ag[ac-1][0] == '-') )
    {  // there is NO input...
        std::cout << "No argument provided" << std::endl;
        //return 1;
	    exit (0);
    }
    else {  // there is an input...
        arg = ag[ac-1];
    }

while(( sw = getopt(ac, ag, "f:")) != -1 )
{
    switch(sw)
    {
        case 'f':
        {
            arg = optarg;
            break;
        }
        case '?':
        {
            std::cout<< "Unknown Argument Provided..!" << std::endl;
            break;
        }
    }

}
return arg;
}
//----------------------------------------------------------