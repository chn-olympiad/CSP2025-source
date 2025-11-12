#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e5+5;

int n,m,k;
int c[N],a[15][N],f[N];

struct node
{
	int u,v,w;
}e[2000005];

bool cmp(node x,node y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			e[++m].u=n+i;
			e[m].v=j;
			e[m].w=a[i][j];
		}
	}
	sort(e+1,e+1+m,cmp);
	int ans=0,cnt=n+k;
	for(int i=1;i<=m;i++){
		int u=find(e[i].u),v=find(e[i].v);
		if(u==v) continue;
		f[v]=u;
		ans+=e[i].w;
		if(++cnt==n+k-1) break;
	}
	cout<<ans;
	return 0;
}

