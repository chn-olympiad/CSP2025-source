#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e4+15;
const int maxm=1e6+10;
int n,m,k;
int newcity[15],dis[maxn];
int h[maxn],to[maxm],nxt[maxm],val[maxm],from[maxm],cnt;
inline void addedge(int u,int v,int w){
	from[++cnt]=u;
	to[cnt]=v;
	val[cnt]=w;
	nxt[cnt]=h[u];
	h[u]=cnt;
}
int Dijkstra(int s,int allt){
	allt+=n-1;
	int tot=0,ans=1e19;
	memset(dis,0x7f7f7f7f,sizeof(dis));
	priority_queue<int,vector<int>,greater<int> > q;
	dis[1]=0;
	for(int i=h[1];i;i=nxt[i]){
		q.push(i);
	}
	while(1){
		if(tot==allt)	break;
		int tmp=q.top();q.pop();
		tot++;
		for(int i=tmp;i;i=nxt[i]){
			int v=to[i],w=val[i],u=from[i];
			if(v>n&&(s&(1<<(v-n-1))==0))	continue;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push(i);
				ans=min(ans,dis[v]);
			}
		}
	}
	for(int j=0;j<k;j++){
		if(s&(1<<j)){
			ans+=newcity[j+1];
		}
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		addedge(u,v,w);
		addedge(v,u,w);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",newcity+i);
		for(int j=1;j<=n;j++){
			int u=n+i,v=j,w;
			scanf("%lld",&w);
			addedge(u,v,w);
			addedge(v,u,w);
		}
	}
	int kk=(1<<k)-1;
	int Ans=1e19;
	for(int i=1;i<=kk;i++){
		int x=0;
		for(int j=0;j<k;j++){
			if(i&(1<<j))	x++;	
		}
		int ans=Dijkstra(i,x);
		Ans=min(ans,Ans);
	}
	printf("%lld",Ans);
	return 0;
}
