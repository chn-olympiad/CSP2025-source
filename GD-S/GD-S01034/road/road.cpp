#include<bits/stdc++.h>
using namespace std;
const int M=1e6+5;
const int N=1e4+5;
int n,m,k,a[15][10010],choose[15],c[15],nn,mm,fa[N*10];
typedef long long ll;
ll ans=2e18,Cost,cost,sum;
bool f=0;
struct edge{
	int u,v,w;
}e[M],ee[M*7];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
vector<int> G[N];
void kruskal(){
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
	    int u=e[i].u,v=e[i].v,w=e[i].w;
	    u=find(u);v=find(v);
	    if(u==v)continue;
	    Cost+=w;
//	    G[u].push_back(v);
//		G[v].push_back(u);
		fa[u]=v;
	}
}
void K(){
	sort(ee+1,ee+1+mm,cmp);
	for(int i=1;i<=nn;i++){
		fa[i]=i;
	}
	for(int i=1;i<=mm;i++){
		int u=ee[i].u,v=ee[i].v,w=ee[i].w;
		u=find(u);v=find(v);
		if(u==v)continue;
		sum+=w;
	    if(sum+cost>ans)return ;
		fa[u]=v;
	}
}
void solve(){
	for(int i=1;i<=m;i++){
		ee[i]=e[i];
	} 
	mm=m;
	nn=n;
	for(int i=1;i<=k;i++){
		if(choose[i]){
			nn++;
			for(int j=1;j<=n;j++){
				ee[++mm]={nn,j,a[i][j]};
			}
		}
	} 
//	if(!f){
//		for(int i=1;i<=mm;i++){
//			cout<<ee[i].u<<" "<<ee[i].v<<' '<<ee[i].w<<'\n';
//		}
//		f=1;
//	}
	sum=0;
	K();
	ans=min(ans,cost+sum);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
		ee[i]=e[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	kruskal();
	if(k==0){
		cout<<Cost<<'\n';
		return 0;
	}
	ans=Cost;
//	cout<<Cost<<'\n';
	for(int bit=1;bit<(1<<k);bit++){
		cost=0;
		for(int i=0;i<k;i++){
			if((bit>>i)&1){
				choose[i+1]=1;
				cost+=c[i+1];
			}
		}
		solve();
		for(int i=1;i<=k;i++){
			choose[i]=0;
		}
	}
	cout<<ans<<'\n';
	return 0;
} 
