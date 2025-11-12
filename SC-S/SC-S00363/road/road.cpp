#include<bits/stdc++.h>
#define ll long long
#define dif(a,b) ((a)^(b)) 
using namespace std;
const int maxn=1e4+25,maxm=2e6+3;
const ll inf=1e18+7;
struct edge{
	int u,v,w;
}eg[maxm],mem[maxm];
random_device rdd;
mt19937 rd(rdd());
inline bool cmp(edge x,edge y){return x.w<y.w;}
int fa[maxn],c[maxn],a[11][maxn],n,m,k,top=0,mx=0;
ll ans=inf;
int findfa(int x){return x==fa[x]?x:fa[x]=findfa(fa[x]);}
void get(ll s,int id){
	ll ret=s;top=0;
	sort(eg+1,eg+m+1,cmp);	
	for(int i=1;dif(i,n+k+1);i=-~i)fa[i]=i;
	for(int i=1,u,v;dif(i,m+1);i=-~i){
		u=eg[i].u,v=eg[i].v;
		u=findfa(u);v=findfa(v);
		if(u!=v){
			ret+=eg[i].w,fa[u]=v;
			mx=max(mx,eg[i].w);
			if(id)mem[++top]=eg[i];
		}
	}
	ans=min(ans,ret);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;dif(i,m+1);i++){
		cin>>u>>v>>w;
		eg[i]={u,v,w};
	}
	get(0,0);
	for(int i=1;i<=m;i++)if(eg[i].w<=mx)mem[++top]=eg[i];
	for(int i=1;dif(i,top+1);i++)eg[i]=mem[i];
	m=top;
	if(top>n*2){
		get(0,1),m=top*2;
		for(int i=1;dif(i,top+1);i++)eg[i]=mem[i];
	}
	for(int i=1;dif(i,k+1);i++){
		cin>>c[i];
		for(int j=1;dif(j,n+1);j++)cin>>a[i][j];
	}
	int maxst=(1<<k)-1;
	for(int i=0;dif(i,maxst+1);i++){
		ll s=0;int bef=m;
		for(int j=1;dif(j,k+1);j++){
			if((i>>(j-1))&1){
				s+=c[j];
				for(int d=1;dif(d,n+1);d++){
					eg[++m]={n+j,d,a[j][d]};
				}
			}
		}
		get(s,0);
		m=bef;
		for(int j=1;dif(j,m+1);j++)eg[j]=mem[j];
	}
	cout<<ans;
	return 0;
}
