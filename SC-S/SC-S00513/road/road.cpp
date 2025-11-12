//if(CCF run nlogn(1e6) in 1s) I love CCF forever;
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e4+10,M=2e6+2e5;
struct EDGE
{
	int u,v,w;
}e[M];
int n,m,k,fa[N],cnt;
ll ans;
bool cmp(EDGE a,EDGE b)
{
	return a.w<b.w;
}
int find(int u)
{
	if(fa[u]==u) return u;
	fa[u]=find(fa[u]);
	return fa[u];
}
void join(int u,int v)
{
	int a=find(u);
	int b=find(v);
	fa[a]=b;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int u=e[i].u,v=e[i].v;
		if(find(u)==find(v))
		{
			join(u,v);
			cnt++;
			ans+=e[i].w;
		}
		if(cnt==n-1) break;
	}
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/