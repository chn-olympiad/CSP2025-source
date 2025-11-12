#include<bits/stdc++.h>
#define int long long
using namespace std;
const int kMaxM=1e6+5,kMaxN=1e4+5;
int n,m,k,cnt;
struct edge{
	int u,v,w;
}e[kMaxM],E[kMaxM];
int c[kMaxN];
int fa[kMaxN],ans;
int find(int x){
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int a[11][kMaxN];
int dis[1005][1005];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0){
		sort(e+1,e+1+m,cmp);
		for(int i=1;i<=m;i++){
			int x=find(e[i].u);
			int y=find(e[i].v);
			if(x!=y){
				fa[x]=y;
				ans+=e[i].w;
			}
		}
		cout<<ans;
		return 0;
	}
	bool flagA=true;
	for(int i=1;i<=k;i++)
		if(c[i]!=0)
			flagA=false;
	if(flagA){
		memset(dis,0x3f,sizeof(dis));
		for(int i=1;i<=m;i++){
			dis[e[i].u][e[i].v]=dis[e[i].v][e[i].u]=e[i].w;
		}
		for(int i=1;i<=n;i++)dis[i][i]=0;
		for(int l=1;l<=k;l++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dis[i][j]=min(dis[i][j],a[l][i]+a[l][j]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][j]==0x3f3f3f3f3f3f3f3f)continue;
				E[++cnt]=edge{i,j,dis[i][j]};
			}
		}
		int sum=0;
		sort(E+1,E+1+cnt,cmp);
		for(int i=1;i<=cnt;i++){
			int x=find(E[i].u);
			int y=find(E[i].v);
			if(x!=y){
				fa[x]=y;
				sum+=E[i].w;
			}
		}
		cout<<sum;
		return 0;
	}
	return 0;
}
