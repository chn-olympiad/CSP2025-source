#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
struct edges{
	int u,v,w;
}e[N];
int n,m,k;
int f[10010];
int a[20][N];
int c[20];
int val;
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
bool cmp(edges aa,edges bb)
{
	return aa.w<bb.w;
}
void fun()
{
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		int x=find(e[i].u);
		int y=find(e[i].v);
		if(x==y) continue;
		f[x]=y;
		cnt++;
		val+=e[i].w;
		if(cnt==n-1) break;
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int iszero=0;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		int zero=0;
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			zero=max(zero,a[i][j]);
		}
		if(zero==0) iszero=1;
	}
	if(iszero==1)
	{
		cout<<0;
		return 0;
	}
	sort(e+1,e+m+1,cmp);
	fun();
	cout<<val;
	return 0;
}
