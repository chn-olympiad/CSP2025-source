#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
long long ans=0x3f3f3f3f3f3f3f3f;
int n,m,k,x,y,z,fx,fy,cnt,b[15],c[N],s[15],fa[N],cc[15][N];
struct node{
	int u,v;long long w;
	bool operator<(const node&x)const{ return w<x.w;}
}a[M];
vector<node>d;
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void solve(int x,long long y){
	for(int i=1;i<=n;++i){
		fa[i]=i;
		c[i]=2e9;
		for(int j=1;j<=x;++j){
			c[i]=min(c[i],cc[b[j]][i]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			d.push_back({i,j,1ll*c[i]+c[j]});
		}
	}
	int l=0;
	sort(d.begin(),d.end());
	for(int i=1;i<=m;i++){
		int u=a[i].u,v=a[i].v,w=a[i].w;
		while(d[l].w<a[i].w&&l<d.size()){
			fx=find(d[l].u),fy=find(d[l].v);
			if(fx!=fy){
				y+=d[l].w;
				fa[fx]=fy;
			}
			l++;
		}
		fx=find(u),fy=find(v);
		if(fx!=fy){
			y+=w;
			fa[fx]=fy;
		}
	}
	ans=min(ans,y);
}
void dfs(int x,int y,long long z){
	if(z>=ans) return;
	if(x>k){
		solve(y,z);
		return;
	}
	dfs(x+1,y,z);
	b[y+1]=x;
	dfs(x+1,y+1,z+s[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&x,&y,&z);
		a[++cnt]={x,y,z};
	}
	sort(a+1,a+m+1);
	bool fl=0;
	for(int i=1;i<=k;++i){
		scanf("%d",&s[i]);
		if(s[i]) fl=1;
		for(int j=1;j<=n;++j){
			scanf("%d",&cc[i][j]);
		}
	}
	if(fl) dfs(1,0,0);
	else{
		for(int i=1;i<=k;i++){
			b[i]=i;
		}
		solve(k,0);
	}
	printf("%lld",ans);
	return 0;
}
