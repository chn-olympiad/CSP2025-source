#include <bits/stdc++.h>
#define For(i,s,e) for(int i=s;i<=e;i++)
#define dFor(i,s,e) for(int i=s;i>=e;i--)
#define int long long
#define mp(a,b) make_pair(a,b)
using namespace std;
const int MaxN=1e4+20;
const int MaxM=2e6+10;
struct edge{
	int v,w,nxt;
}e[MaxM];
int tot,head[MaxN],c[11];
void add(int u,int v,int w){
	e[++tot]=(edge){v,w,head[u]};
	head[u]=tot;
}
int n,m,k,dis[MaxN],ans=0,vis[MaxN];
int tr(int s){
	int sum=0;
	memset(vis,0,sizeof(vis));
	priority_queue<pair<int,pair<int,int> > >q;
	For(i,0,MaxN-1)dis[i]=-1;
	dis[s]=0;
	q.push(mp(0,mp(s,0)));
	while(q.size()){
		int l=-q.top().first,u=q.top().second.first,ls=q.top().second.second;
//			cout<<u;
		vis[u]=1;
		q.pop();
		if(dis[u]!=-1 && l>dis[u])continue;
		sum+=e[ls].w;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].v,w=e[i].w;
			if(vis[v])continue;
			if(dis[i]==-1 || l+w<dis[v]){
				dis[v]=l+w;
				q.push(mp(-dis[v],mp(v,i)));
			}
		}
	}
	return sum;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	For(i,1,m){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	For(i,1,k){
		int a;
		scanf("%lld",c+i);
		For(j,1,n){
			scanf("%lld",&a);
			add(n+i,j,a);
			add(j,n+i,a);
		}
	}
	For(i,1,n+k){int t=tr(i);/*cout<<t<<endl;*/ans=i==1?t:(ans<t?ans:t);}
	printf("%lld",ans);
    return 0;
}
/*
4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
bie dang wo de lu!
*/
