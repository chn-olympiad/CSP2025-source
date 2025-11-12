#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int rd()
{
	int x=0,c,f=1;
	c=getchar();
	while(c<'0'||c>'9')
	{
		f=-f;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,k;
int u,v,w;
int sum=0;
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		u=rd();
		v=rd();
		w=rd();
		sum+=w;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++)u=rd();
	}
	cout<<sum;
		
}
