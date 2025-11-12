#include<bits/stdc++.h>
#define ll long long
//password Ren5Jie4Di4Ling5%
using namespace std;
const int N=1e4+100,M=1e6+10,K=N+M+100;
int fa[N];int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
struct Edge{
	int u,v;ll w;
	bool operator<(const Edge &oth) const{
		return w<oth.w;
	}
}e[K];
ll cty[100][N];
int n,m,k,cnt;ll eg[N][N];
ll ans;
void kruskal(){
	int i;
	for(i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,fu=find(u),fv=find(v);
		if(fu==fv) continue;
		ans+=e[i].w;
		fa[fu]=fv;
	}
}
int main(){
		//freopen!!!!!!!!!!!!
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j;
	cin>>n>>m>>k;
	for(i=1;i<=n;i++) fa[i]=i;
	for(i=1;i<=m;i++){
		int u,v;ll w;
		cin>>u>>v>>w;
		if(u==v) continue;
		e[++cnt]={u,v,w};
		eg[u][v]=eg[v][u]=w;
	}
	for(i=1;i<=k;i++){
		cin>>cty[i][0];
		for(j=1;j<=n;j++){
			cin>>cty[i][j];
		}
	}
	for(i=1;i<=k;i++){
		ll ctg=cty[i][0],now=0;
		bool bk1=0;int p=cnt;
		sort(e+1,e+cnt+1);
		for(j=cnt;j>=1;j--){
			int u=e[j].u,v=e[j].v;ll w=e[j].w;
			now+=w;
			ctg+=cty[i][u]+cty[i][v];
			if(ctg>now&&!bk1){
				bk1=1;
			}
			if(bk1&&ctg<now){
				p=j+1;
				break;
			}
		}
		if(p!=cnt) ans+=cty[i][0];
		for(j=cnt;j>=p;j--){
			e[j].w=cty[i][e[j].u]+cty[i][e[j].v];
		}
	}
	sort(e+1,e+cnt+1);
	kruskal();
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
