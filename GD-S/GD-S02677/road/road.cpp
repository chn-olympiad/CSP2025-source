#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e4+500,M=1e6+5,K=12;

int n,m,k;
int cnt,tmp,necnt;
struct edge{
	int u,v;
	ll w;
	
	bool operator <(const edge& it) const{
		return this->w<it.w;
	}
	
}e[M*2],ne[M*10];
ll tow[K];
ll nbri[K][N]; 

void add(int u,int v,ll w){
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
}

void add1(int u,int v,ll w){
	ne[++necnt].u=u;
	ne[necnt].v=v;
	ne[necnt].w=w;
}

int poi,goal;
ll ans;

int fa[N];
int find(int x){
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}

int npoi[K];
bool vis[K];

ll ans1=1e18;
void solve(int npcnt){
	ans=0,poi=0;
	memcpy(ne,e,sizeof(e));
	necnt=tmp;
	for(int u,i=1;i<=npcnt;i++){
		u=npoi[i];ans+=tow[u];
		for(int j=1;j<=n;j++){
			add1(u+n,j,nbri[u][j]);
//			add1(j,u+n,nbri[u][j]);
		}
	}
	
	sort(ne+1,ne+1+necnt);
	for(int i=1;i<=n+k*2;i++){
		fa[i]=i;
	}
	goal=n+npcnt-1;
	for(int i=1;i<=necnt;i++){
		int u=ne[i].u;
		int v=ne[i].v;
		int fu=find(u);int fv=find(v);
		ll w=ne[i].w;
		if(fu==fv) continue;
		
		ans+=w;
		fa[fu]=fa[fv];
		poi++;
		if(poi==goal) break;
	}
	ans1=min(ans,ans1);
}

void dfs(int x,int goal){
	if(x>goal){
		solve(goal);
		
		return ;
	}
	for(int i=1;i<=k;i++){
		if(vis[i]) continue;
		vis[i]=1;
		npoi[x]=i;
		dfs(x+1,goal);
		vis[i]=0;
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	
	int x,y;
	ll w;
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&x,&y,&w);
		add(x,y,w);
//		add(y,x,w);
	}
	tmp=cnt;
	for(int j=1;j<=k;j++){
		scanf("%lld",&tow[j]);
		for(int i=1;i<=n;i++){
			scanf("%lld",&nbri[j][i]);
			
		}	
	}
	if(k==0){
		sort(e+1,e+1+cnt);
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		goal=n-1;
		for(int i=1;i<=cnt;i++){
			int u=e[i].u;
			int v=e[i].v;
			int fu=find(u);int fv=find(v);
			ll w=e[i].w;
			if(fu==fv) continue;
			
			ans+=w;
			fa[fu]=fa[fv];
			poi++;
			if(poi==goal) break;
		}
		printf("%lld\n",ans);
	}
	else{
		for(int i=0;i<=k;i++){
			dfs(1,i);
		}
		printf("%lld\n",ans1);
	}
	
	return 0;
} 
