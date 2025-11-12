#include<bits/stdc++.h>
#define Mp make_pair
#define eb emplace_back
#define il inline
#define pc putchar
#define gc getchar
#define mems(x,y) memset(x,y,sizeof x)
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define drep(i,x,y) for(int i=(x);i>=(y);i--)
#define go(i,u) for(int i=head[u];i;i=e[i].nxt)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e4+7,M=1e6+7,inf=0x3f3f3f3f,mod=0;
const ll INF=1ll*inf*inf;
il void read(int &x){
	x=0;int f=1;
	char c=gc();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=gc();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=gc();
	}
	x*=f;
}
int n,m,k,c[N];
struct node{
	int u,v,w;
}E[M],e[N*10];
struct DSU{
	int fa[N];
	void init(){
		rep(i,1,n+k){
			fa[i]=i;
		}
	}
	int fd(int x){
		return fa[x]==x?x:fa[x]=fd(fa[x]);
	}
	il void merge(int x,int y){
		x=fd(x),y=fd(y);
		fa[x]=y;
	}
}D;
il bool cmp(node x,node y){
	return x.w<y.w;
}
void Sana(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,m){
		read(E[i].u),read(E[i].v),read(E[i].w);
	}
	sort(E+1,E+m+1,cmp);
	D.init();
	int p=0;
	rep(i,1,m){
		int u=E[i].u,v=E[i].v,w=E[i].w;
		if(D.fd(u)!=D.fd(v)){
			D.merge(u,v);
			e[++p]=E[i];
		}
	}
	rep(i,1,k){
		scanf("%d",&c[i]);
		rep(j,1,n){
			int w;scanf("%d",&w);
			e[++p]={n+i,j,w};
		}
	}
	sort(e+1,e+p+1,cmp);
	const int all=1<<k;
	ll ans=INF;
	rep(S,0,all-1){
		ll nans=0;
		rep(i,1,k){
			if(S>>(i-1)&1){
				nans+=c[i];
			}
		}
		D.init();
		rep(i,1,p){
			int u=e[i].u,v=e[i].v,w=e[i].w;
			if(u>n&&!(S>>(u-n-1)&1)){
				continue;
			}
			if(D.fd(u)!=D.fd(v)){
				D.merge(u,v);
				nans+=w;
			}
		}
		ans=min(ans,nans);
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int t=1;
	// scanf("%d",&t);
	while(t--){	
		Sana();
	}
}
