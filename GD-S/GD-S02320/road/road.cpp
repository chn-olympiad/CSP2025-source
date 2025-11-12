#include<bits/stdc++.h>
#define int long long
const int N=1e4+22;
using namespace std;
struct node{
	int x,y,val;
	
	friend bool operator < (node x,node y){
		return x.val<y.val;
	}
};
int n,m,k,f[N][N],a[12][N],c[12],ans,fa[N];
vector <node> e;
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void kruskal(){
	sort(e.begin(),e.end());
	int cnt=0;
	for(int i=0;i<e.size() && cnt<n;i++){
		int xx=find(e[i].x),yy=find(e[i].y);
		if(xx==yy) continue ;
		fa[xx]=yy;
		cnt++;
		ans+=e[i].val;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	memset(f,127,sizeof(f));
	for(int i=1;i<=n;i++) fa[i]=i,f[i][i]=0;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		f[u][v]=f[v][u]=w;
	}
	for(int o=1;o<=k;o++){
		scanf("%lld",&c[o]);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[o][i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<n;j++){
				f[i][j]=f[j][i]=min(f[i][j],c[o]+a[o][i]+a[o][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++) cout<<f[i][j]<<' ';
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			e.push_back({i,j,f[i][j]});
		}
	}
	kruskal();
	printf("%lld",ans);
}
