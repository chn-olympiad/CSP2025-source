#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[10100][10100],s[20][10100];
long long minn=2147483647;
bool fl[10100];
void go(int where,int st,long long need)
{
	if(need>=minn)return ;
	if(st==n)
	{
		minn=need;return;
	}
	for(int i=1;i<=n;i++)
	{
		if(c[where][i]>0&&fl[i]==false)
		{
			fl[i]=true;
			go(i,st+1,need+c[where][i]);
			fl[i]=false;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		int u,v,w;cin>>u>>v>>w;
		c[u][v]=w;c[v][u]=w;
	}
	for(int i=1;i<=k;i++)
	    for(int j=0;j<=n;j++)cin>>s[i][j];
	go(1,1,0);
	cout<<minn;
	return 0;
}
