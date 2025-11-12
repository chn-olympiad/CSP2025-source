#include <iostream>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a,b;
	cin>>a>>b;
	if(a>b)
    {
    	cout<<a<<b;
	}
	else
	{
		cout<<b<<a;
	}
}
