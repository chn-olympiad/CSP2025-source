#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[10005];
long long ans=1e18,c[12];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
struct myq{int u,v;long long w;} g[1500005],g2[12][10005],tmp[1500005];
long long kruskal(int n,int m){
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)tmp[i]=g[i];
	sort(tmp+1,tmp+m+1,[](myq x,myq y){return x.w<y.w;});
	long long res=0;
	for(int i=1;i<=m;i++){
		int x=find(tmp[i].u),y=find(tmp[i].v);
		if(x!=y)fa[x]=y,res+=tmp[i].w;
	}
	return res;
}
bool cho[12],ok=true;
void dfs(int u){
	if(u>k){
		int cntn=0,cntm=0;
		long long sum=0;
		for(int i=1;i<=k;i++)
			if(cho[i]){
				cntn++,sum+=c[i];
				for(int j=1;j<=n;j++)g[m+(++cntm)]=g2[i][j];
			}
		long long tmp=kruskal(n+cntn,m+cntm);
		ans=min(ans,tmp+sum);
		return;
	}
	if(!ok)dfs(u+1);
	cho[u]=true,dfs(u+1),cho[u]=false;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>g[i].u>>g[i].v>>g[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i])ok=false;
		for(int j=1;j<=n;j++)cin>>g2[i][j].w,g2[i][j].u=n+i,g2[i][j].v=j;
	}
	dfs(1),cout<<ans;
	return 0;
}
