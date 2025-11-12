#include<bits/stdc++.h>
#define rep(i,n,m) for(int i=n;i<=m;++i)
#define ref(i,n,m) for(int i=n;i>=m;--i)
#define ll long long
using namespace std;
const int N=1e4+5,M=1e6+5;
struct Edge{
	int u,v;
	ll w;
}g[M],ex[N*10]; 
ll ans=1e18,cost[11];
int n,m,k,tot,fa[N+11],siz[N+11],to[11][N];
bool cmp(Edge A,Edge B){
	return A.w<B.w;
}
int Find(int x){
	return fa[x]=(x==fa[x]?x:Find(fa[x]));
}
void merge(int u,int v){
	int x=Find(u),y=Find(v);
	if(x==y) return ;
	if(siz[y]>siz[x]) swap(x,y);
	siz[x]+=siz[y];
	fa[y]=x;
}
ll K(int S){
	ll res=0;
	int TOT=0,cnt=0;
	rep(i,0,9){
		if((1<<i)&S){
			++cnt;
			rep(j,1,n) ex[++TOT]={j,n+cnt,to[i+1][j]};
			res+=cost[i+1];
		}
	}
	rep(i,1,n+cnt) fa[i]=i,siz[i]=1;
	sort(ex+1,ex+TOT+1,cmp);
//	return 0;
	for(int i=1,j=1,k=1;k<n+cnt;){
//		cout<<S<<"  "<<i<<" "<<j<<" "<<k<<":\n";
//		cout<<g[i].u<<" "<<g[i].v<<" "<<g[i].w<<"\n";
//		cout<<ex[j].u<<" "<<ex[j].v<<" "<<ex[j].w<<"\n";
		if((g[i].w<=ex[j].w||j>TOT)&&i<tot){
			if(Find(g[i].u)==Find(g[i].v)) ++i;
			else merge(g[i].u,g[i].v),++k,res+=g[i++].w;
		}
		else{
			if(Find(ex[j].u)==Find(ex[j].v)){
				while(j<=TOT&&Find(ex[j].u)==Find(ex[j].v)) ++j;
				continue;
			}
			else merge(ex[j].u,ex[j].v),++k,res+=ex[j++].w;
		}
	}
	return res;
}
bool check(){
	rep(i,1,k) if(cost[i]!=0) return 0;
	return 1;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	rep(i,1,m){
		int u,v,w;
		cin>>u>>v>>w;
		g[++tot]={u,v,w};
//		if(tot%10==0) cout<<tot<<"\n";
	}
//	return 0;
	rep(i,1,k){
		cin>>cost[i];
		rep(j,1,n) cin>>to[i][j];
	}
	if(check()&&n>1000&&m>100000){
		cout<<K((1<<k)-1);
		return 0;
	}
	sort(g+1,g+tot+1,cmp);
	rep(Situation,0,(1<<k)-1){
//		cout<<Situation<<"\n";
		ans=min(K(Situation),ans);
	}
	cout<<ans;
}
