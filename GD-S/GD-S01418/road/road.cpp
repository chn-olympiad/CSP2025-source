#include<bits/stdc++.h>
#define psb push_back
#define fi first
#define se second
#define endl '\n'
#define int long long
using namespace std;
const int N=1e4+3,K=12,M=1e6+5;
struct edge{int u,v,w;bool operator<(edge b){return w<b.w;}} e[M+N*K];
int n,m,k,c[K],a[K][N],fa[N+K];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			e[++m]={n+i,j,a[i][j]};
		}
	}
	sort(e+1,e+1+m);
	for(int i=1;i<=n+k;i++)fa[i]=i;
	int ans=0;
	for(int i=1;i<=m;i++){
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu!=fv){
			ans+=e[i].w;
			fa[fu]=fv;
		}
	}
	cout<<ans<<endl;
	return 0;
}/*

*/
