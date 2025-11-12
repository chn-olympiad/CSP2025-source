#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int a[11][N],fa[N];
long long ans;
struct edge{
	int u,v;
	long long w;
};
vector<edge> e;
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<m;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		e.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		int c;
		scanf("%d",&c);
		for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
		for(int x=1;x<=n;x++){
			for(int y=x+1;y<=n;y++){
				e.push_back({x,y,(long long)c+a[i][x]+a[i][y]});
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(e.begin(),e.end(),cmp);
	for(long long i=0;i<e.size();i++){
		if(cnt==n-1) break;
		edge t=e[i];
		long long u=t.u,v=t.v,w=t.w;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			fa[fu]=fv;
			ans+=w;
			cnt++;
		}
	}
	printf("%lld",ans);
	return 0;
}

