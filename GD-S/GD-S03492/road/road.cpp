#include <bits/stdc++.h>
const int N=1e4+10;
using namespace std;
typedef long long ll;
int n,m,k,cnt;
int fa[N],vis1[15],vis2[15][N];
ll a[15][N],c[15],ans;
struct edge{
	int u,v,op,z;
	ll w;
	bool operator<(const edge& other){
		return w<other.w;
	}
};
vector<edge> e;
void init(){
	sort(e.begin(),e.end());
	for(int i=1;i<=n;i++)
		fa[i]=i;
}
int find(int x){
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
bool merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy)
		return false;
	fa[fx]=fy;
	return true;
}
void kruskal(){
	int tot=0;
	init();
	for(auto t:e){
		int u=t.u,v=t.v,op=t.op,z=t.z;
		ll w=t.w;
		if(merge(u,v)){
			ans+=w,tot++;
			if(op){
				if(!vis1[z])
					vis1[z]=1;
				else
					ans-=c[z];
				if(!vis2[z][u])
					vis2[z][u]=1;
				else
					ans-=a[z][u];
				if(!vis2[z][v])
					vis2[z][v]=1;
				else
					ans-=a[z][v];
			}
			if(tot>=n-1)
				return;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		scanf("%d%d%lld",&u,&v,&w);
		e.push_back({u,v,0,0,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%lld",&a[i][j]);
		for(int j=1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				e.push_back({j,k,1,i,c[i]+a[i][j]+a[i][k]});
	}
	kruskal();
	printf("%lld",ans);
	return 0;
}
