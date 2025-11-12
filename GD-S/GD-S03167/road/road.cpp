#include<bits/stdc++.h>
#define int long long
#define mk(a,b) make_pair(a,b)
using namespace std;

//Prim（类似特殊最短路）
constexpr int N=1e4+105,M=1e6+5,K=15,L=(1<<10)+5;
int n,m,k,u,v,w,whx=1e18+7;
int c[K],a[K][M],d[N][L],ans[L],vis[N][L];
priority_queue<pair<int,pair<int,int> > >q;//表示在se.se的状态下点se.fi到集合的距离fi 
vector<pair<int,int> >e[N];//表示u到se的距离为fi 

void prim(){
	memset(d,0x3f3f3f,sizeof(d));
	d[1][0]=0;
	q.push(mk(0,mk(1,0)));
	for(;!q.empty();){
		auto res=q.top(); q.pop();
		int now=res.second.first,type=res.second.second;
		if(vis[now][type]) continue;
		ans[type]-=res.first;
		//cout<<now<<" "<<type<<" "<<-res.first<<endl;
		vis[now][type]=1;
		if(now>n){
			for(int next=1;next<=n;next++){
				int w=a[now-n][next];
				if(d[next][type]>w&&!vis[next][type]){
					d[next][type]=w;
					q.push(mk(-w,mk(next,type)));
				}
			}
			continue;
		}
		for(auto tmp:e[now]){
			int next=tmp.second,w=tmp.first;
			if(d[next][type]>w&&!vis[next][type]){
				d[next][type]=w;
				q.push(mk(-w,mk(next,type)));
			}
		}
		for(int i=1;i<=k;i++){
			int p=1<<(i-1),tmp=c[i],ntype=type|p;
			if(type&p) continue;
			q.push(mk(-tmp,mk(n+i,ntype)));
		}
	}
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		e[u].push_back(mk(w,v));
		e[v].push_back(mk(w,u));
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) scanf("%lld",&a[i][j]);
	}
	prim();
	for(int i=0;i<(1<<k);i++) whx=min(whx,ans[i]);
	cout<<whx;
}
