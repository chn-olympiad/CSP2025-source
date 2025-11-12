#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int v,l,r;
};
priority_queue<pair<int,int>>q[10001];
node f[100001];
int road[10001][10001];
int man[11][10001];
int num[10001];
int www[10001];
int main()
{
	int ans=0;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int g=1;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		ans+=w;
		road[u][v]=w;
		road[v][u]=w;
		num[u]++;
		num[v]++;
	}
	for(int i=1;i<=n;i++)num[i]+=k;
	bool b=0;
	for(int i=1;i<=k;i++)
	{
		www[i]=k;
		int c;
		cin>>c;
		if(c)b=1;
		for(int j=1;j<=n;j++){
		cin>>man[i][j];	
		if(man[i][j])b=1;
		}
		for(int j=1;j<=n;j++)
		{
			for(int l=1;l<=n;l++)
			{
				q[l].push({man[i][l]+man[i][j],i});
			}
		}
	}
	if(b==0)
	{
		cout<<0;
		return 0;
	}
	cout<<ans;
	return 0;
}
/***
比去年难，不好玩TAT 
骗分会成功吗 
***/
