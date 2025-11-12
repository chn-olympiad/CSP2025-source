#include<bits/stdc++.h>
using namespace std;
long long int n;
long long int b[120101];
long long int a[101010];
long long int cnt=0;
long long int vis[101101];
long long int jian=0;
void choose(long long int x,long long int m,long long int pre)
{
	if(x==m+1)
	{
		long long int hk[10101];
		memset(hk,0,sizeof(hk));
		long long int sum=0,maxx=-1;
		for(long long int i=1;i<=m;i++)
		{
			if(b[i]>maxx)
			{
				maxx=b[i];
			}
			sum+=b[i];
		}
		if(sum>2*maxx)
		{
			cnt++;
		}
	}
	else
	{
		for(long long int i=1;i<=n;i++)
		{
			if(vis[i]==0 and i>pre)
			{
				vis[i]=1;
				b[x]=a[i];
				choose(x+1,m,i);
				vis[i]=0;
			} 
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long int i=3;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		choose(1,i,0);
	} 
	cout<<cnt;
}
/*
2 2 3
3 8 10
2 2 8 10
2 3 8 10
2 3 8 10
2 2 3 8 10
*/
