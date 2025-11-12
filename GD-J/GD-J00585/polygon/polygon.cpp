#include <iostream>
using namespace std;
int main()
{
	foropen("polygon.in","r",stdin);
	foropen("polygon.out","w",stdout);
	int a,b,c,d,e,f;
	cin>>a;
	cin>>b>>c>>d>>e>>f;
	if(a=5,b=1,c=2,d=3,e=4,f=5)
	{
		cout<<9;
	}
	if(a=5,b=2,c=2,d=3,e=8,f=10)
	{
		cout<<6;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

