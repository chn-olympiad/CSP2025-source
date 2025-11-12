#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+10,M=1e7+1000;
int n,m,k;
struct node{
	int u,v,w,f;
}e[M];
int c[11];
int kij[11][N];
int fa[N];
bool cmp(node x,node y){return x.w<y.w;}
int find(int x){ return (fa[x]==x?x:find(fa[x]));}
bool vis[11];
int b[N][N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	memset(b,0x3f,sizeof(b));
	cin>>n>>m>>k;
	int len=m;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>kij[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		for(int u=1;u<=n;u++){
			for(int v=u+1;v<=n;v++){
				if(b[u][v]>kij[i][u]+kij[i][v])b[u][v]=kij[i][u]+kij[i][v];
			}
		}
	}
	if(k>0){
		for(int u=1;u<=n;u++){
			for(int v=u+1;v<=n;v++){
				if(b[u][v]<=2e9) e[++len].u=u,e[len].v=v,e[len].w=b[u][v];
			}
		}
	}
	sort(e+1,e+1+len,cmp);
	int ans=0;
	int t=n;
	for(int i=1;i<=len;i++){
		if(find(e[i].u)!=find(e[i].v)){
			ans+=e[i].w;
			if(!vis[e[i].f]) vis[e[i].f]=1,ans+=c[e[i].f];
			fa[find(e[i].u)]=find(e[i].v);
			t--;
		}
		if(t==1) break;
	} 
	cout<<ans;
	return 0;
}

