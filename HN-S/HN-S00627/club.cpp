#include<iostream>
using namespace std;
int main()
{
	int n=0,a1=0,a2=0,a3=0,an=0,I=0,A1=0,A2=0,A3=0;
	cin>>I;
	for (int j=0;j<=I;j++)
	{
		cin>>a1,a2,a3;
		if((a1>a2 && a1>a3 && A1<=I/2)
		{
			an=a1;
		    A1=A1+1;}
		    else
			    if(a2>a3 && A2<=I/2)
			    {
		            an=a2;
		            A2=A2+1;}
		        else
				    if(A3<=I/2)
				    {
		            an=a3;
		            A3=A3+1;}
		                else    if((a1>a2))
		                {
		                    an=a1;
		                    A1=A1+1;}
		                    else
		                    {
		                        an=a2;
		                        A2=A2+1;
		                    }
	    a1=a2=a3=0;
	    n=n+an;
	    an =0;
	}
	cout<<n<<endl;
	return 0; 
}
