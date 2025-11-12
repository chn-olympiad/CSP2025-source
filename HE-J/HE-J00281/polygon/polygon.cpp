#include <iostream>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,b,c,d=3;
	cin>>d>>a>>b>>c;
	if(a>b and a>c)
	{
		if(a+b+c>2*a)
	    {
		    cout<<"1";
	    }
	    else
	    {
	    	cout<<"0";
		}
	}
    if(c>b and c>a)
	{
		if(c+b+a>2*c)
	    {
		    cout<<"1";
	    }
	     else
	    {
	    	cout<<"0";
		}
	}
	if(b>a and b>c)
	{
		if(b+a+c>2*b)
	    {
		    cout<<"1";
	    }
	     else
	    {
	    	cout<<"0";
		}
	}
}
