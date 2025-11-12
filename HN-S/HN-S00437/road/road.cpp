#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4+10;
const int M = 1e6+10;
int n,m,k,u,v,w,a[11][N],f[N];
struct E{
	int u,v,w;
}edge[M];
bool cmp(E x,E y){
	return x.w<y.w;
}
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i) f[i]=i;
	for(int i=1;i<=m;++i){
		cin>>u>>v>>w;
		edge[i].u=u;
		edge[i].v=v;
		edge[i].w=w;
	}
	for(int i=1;i<=k;++i){
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
		}
	}
	sort(edge+1,edge+m+1,cmp);
	int ans=0;
	for(int i=1;i<=m;++i){
		int x=find(edge[i].u);
		int y=find(edge[i].v);
		if(x==y) continue;
		ans+=edge[i].w;
		f[x]=y;
	}
	cout<<ans;
	return 0;
}

