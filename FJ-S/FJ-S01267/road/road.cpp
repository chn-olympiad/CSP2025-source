#include<iostream>
#include<stdio.h>
#include<algorithm>
#define N 10005
#define M 1000005
#define ll long long
using namespace std;
int n,m,k;
ll ans;
int cnt,head[N],to[M<<1],nxt[M<<1],val[M<<1];
int va[M];
void add(int u,int v,int w)
{
	to[++cnt]=v;
	val[cnt]=w;
	nxt[cnt]=head[u];
	head[u]=cnt;
}
void dfs(int x)
{
	for(int i=head[x];i;i=nxt[x])
	{
		//int y=to[x];
		
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
    	int u,v,w;
    	cin>>u>>v>>w;
    	va[i]=w;
		add(u,v,w);
		add(v,u,w);
	}
	//dfs(1);
	sort(va+1,va+m+1);
	for(int i=1;i<n;i++)
	    ans+=va[i];
	cout<<ans; 
	return 0;
}
