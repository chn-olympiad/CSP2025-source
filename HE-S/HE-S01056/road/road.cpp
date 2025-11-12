#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e7+7,M=1e4+7;
struct edge{
	int u,v,w;
}e[N];
int n,m,k;
int c[110];
bool f[110];
int a[M][M];
inline bool cmp(edge x,edge y){
	return x.w<y.w;
}
int fa[N];
inline int find(int x){
	return fa[x]==x? x:fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	int len=m;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
		for(int j=1;j<=n;j++){
			for(int h=1;h<=n;h++){
				if(j==h) continue;
				len++;
				e[len].u=j;
				e[len].v=h;
				e[len].w=c[i]+a[i][j]+a[i][h];
			}
		}
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	int ans=0;
	sort(e+1,e+len+1,cmp);
	for(int i=1;i<=len;i++){
		int tx=find(e[i].u);
		int ty=find(e[i].v);
		if(tx!=ty){
			fa[tx]=ty;
			ans+=e[i].w;
		}
	}
	cout<<ans;
	return 0;
}
