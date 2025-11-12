#include<bits/stdc++.h>
using namespace std;
int xianyu(int a,int b)
{
	return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,b[121];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>b[i];
	}
	int c=b[1],d;
	sort(b+1,b+1+m*n,xianyu);
	for(int i=1;i<=m*n;i++)
	{
		if(b[i]==c)
		{
			d=i;
		}
	}
	if(d%n!=0) c=d/n+1;
	if(d%n==0) c=d/n;
	if(c%2==1)
	{
		if(d%n==0) cout<<c<<" "<<n;
		else cout<<c<<" "<<d%n;
	}
	else if(c%2==0)
	{
		if(d%n==0) cout<<c<<" "<<"1";
		else cout<<c<<" "<<n-(d%n)+1;
	}
    return 0;
}
