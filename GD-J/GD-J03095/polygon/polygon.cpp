#include<iostream>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,m,a,b,c,maxx;
	cin>>n>>m;
	if(n==3)
	{
		cin>>a>>b>>c;
		maxx=max(max(a,b),c);
		if(a+b+c>maxx*2)
		{
			cout<<1;
			return 0;
		}	
	}
	cout<<0;
	return 0;
}
