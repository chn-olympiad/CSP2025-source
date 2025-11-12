#include <iostream>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;

const int MAXN=1e4+5;
const int MAXM=21e5+5;
const int MAXK=15;

typedef long long LL;

int n,m,k,tot=1;

int head[MAXN],frontf[MAXN];

bool checkA=1;

LL ansa=inf,ansb,ansc,ansd;

LL c[MAXN],a[MAXK][MAXN];

struct Data{
	int u,v,w;
	bool operator <(const Data &temp) const{
		return temp.w<w;
	}
};

struct Road{
	int nxt,to,val;
}edge[MAXN<<1];

priority_queue <Data> Q;

void init(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		Q.push({u,v,w});
	}
	
	if (!k){
		checkA=0;
	}
	for (int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for (int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if (a[i][j]){
				checkA=0;
			}
		}
	}
	
	for (int i=1;i<=n;i++){
		frontf[i]=i;
	}
	return;
}

void add(int u,int v,LL w){
	edge[++tot].to=v;
	edge[tot].val=w;
	edge[tot].nxt=head[u];
	head[u]=tot;
	return;
}

int Find(int now){
	return frontf[now]==now?now:frontf[now]=Find(frontf[now]);	
}

void solve(){
	int temp=n;
	while (temp!=1){
		Data t=Q.top();
		Q.pop();
		int fa_u=Find(t.u);
		int fa_v=Find(t.v);
		if (fa_u!=fa_v){
			add(t.u,t.v,t.w);
			add(t.v,t.u,t.w);
			frontf[fa_u]=fa_v;
			ansb+=t.w;
			temp--;
		}
	}
	
	if (!k){
		printf("%lld",ansb);
		return;
	}
	if (checkA){
		for (int i=1;i<=k;i++){
			ansa=min(ansa,c[i]);
		}
		printf("%lld",min(ansa,ansb));
		return;
	}
	printf("%lld",min(ansa,ansb));
	return;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	init();
	solve();
	return 0;
}
