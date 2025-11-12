#include <iostream>
using namespace std;
int main()
{
	foropen("number.in","r",stdin);
	foropen("number.out","w",stdout);
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>f;
	if(a>b>c>d>e>f)
	{
		cout<<a<<b<<c<<d<<e<<f;
	}
	elseif(a<b<c<d<e<f)
	{
		cout<<f<<e<<d<<c<<b<<a;
	}
	elseif(a>b>c>d>f>e)
	{
		cout<<a<<b<<c<<d<<f<<e;
	}
	lose(stdin);
	fclose(stdout);
	return 0;
}
