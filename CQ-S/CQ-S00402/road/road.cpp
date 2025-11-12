#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e4+5,MAXM=1e6+5;
struct node{
	int x,y,w;
};
vector<node>e;
int vis[15];
int n,m,k,c[15],dis[15][MAXN];
bool cmp(node x,node y){
	return x.w<y.w;
}
int fa[MAXN];
int findd(int x){
	if(fa[x]==x)return x;
	else return fa[x]=findd(fa[x]);
}
int sum=0,ans=2e9;
int tag[MAXN][12];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int x,y,w;
		scanf("%lld %lld %lld",&x,&y,&w);
		e.push_back({x,y,w});
	}
	int mx=0;
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		mx=max(mx,c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&dis[i][j]);
			mx=max(mx,dis[i][j]);
		}
	}
	if(mx==0){
		printf("0");
	}else{
		sort(e.begin(),e.end(),cmp);
		for(int i=0;i<m;i++){
			int x=e[i].x,y=e[i].y,w=e[i].w;
			int fx=findd(x),fy=findd(y);
			if(fx==fy)continue;
			fa[fx]=fy;
			sum+=w;
		}
		ans=sum;
		printf("%lld",ans);	
	}
	return 0;
} 
