#include<bits/stdc++.h>
#define int long long
using namespace std;
/*struct edge{
	int u,v,w;
}a[1000010];*/
struct node {
	int c;
	vector<int> a;
} b[10010];
int mp[10010][10010];
int s[10010];
/*bool cmp(edge x,edge y)
{
	return x.w>y.w;
}*/
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1; i<=m; ++i) {
//		cin>>a[i].u>>a[i].v>>a[i].w;
		int u=0,v=0,w=0;
		cin>>u>>v>>w;
		mp[u][v]=mp[v][u]=w;
	}
	for(int i=1; i<=k; ++i) {
		int x;
		cin>>b[i].c;
		for(int i=1; i<=n; ++i) {
			cin>>x;
			b[i].a.push_back(x);
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			for(int l=1;l<=k;++l)
			{
				mp[i][j]=min(mp[i][j],b[l].a[j-1]+b[l].a[j-1]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		int mi=100000000;
		for(int j=1;j<=n;++j)
		{
			if(i==j) continue;
			if(s[i]=j) continue;
			mi=min(mp[i][j],mi);
		}
		s[mi]=1;
		ans+=mi;
	}
	cout<<ans;
	return 0;
}

