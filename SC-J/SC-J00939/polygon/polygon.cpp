#include<bits/stdc++.h>
using namespace std;
int a,b,c,n;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3)
	{
		cin>>a>>b>>c;
		int maxx=max(max(a,b),c);
		if(a+b+c>2*maxx)	cout<<1;
		else	cout<<0;
	}
	return 0;
}