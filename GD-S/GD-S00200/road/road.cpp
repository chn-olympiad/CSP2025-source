#include <bits/stdc++.h>
using namespace std;
int n,m,k,f[10020],t[15],a[15];
long long c[15],ans=1e16;
struct edge{
	int u,v;
	long long w;
}e[1000010],g[15][10010];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
void hb(int x,int y){
	f[find(x)]=find(y);
}
bool cmp(const edge &x,const edge &y){
	return x.w<y.w;
}
edge nex(){
	int tag=0;long long res=e[t[0]].w;
	for(int i=1;i<=k;i++){
		if(a[i]&&t[i]<=n&&res>g[i][t[i]].w){
			tag=i;
			res=g[i][t[i]].w;
		}
	}
	++t[tag];
	if(!tag) return e[t[0]-1];
	return g[tag][t[tag]-1];
}
void work(long long tot,int l){
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=0;i<=k;i++) t[i]=1;
	int cnt=1;long long res=tot;
	while(cnt<l){
		edge p=nex();
		int u=p.u,v=p.v;long long w=p.w;
		if(find(u)!=find(v)){
			res+=w;
			//cout<<u<<' '<<v<<endl;
			cnt++;
			hb(u,v);
		}
	}
	//cout<<res<<endl;
	ans=min(ans,res);
}
void dfs(int s,long long tot,int l){
	if(s>k){
		work(tot,l);
		return ;
	}
	dfs(s+1,tot,l);
	a[s]=1;
	dfs(s+1,tot+c[s],l+1);
	a[s]=0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&g[i][j].w);
			g[i][j].u=n+i,g[i][j].v=j;
		}
		sort(g[i]+1,g[i]+n+1,cmp);
	} 
	dfs(1,0,n);
	cout<<ans;
	return 0;
}

