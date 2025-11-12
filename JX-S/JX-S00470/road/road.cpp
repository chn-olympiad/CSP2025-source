#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
const int SZ=1e4+20;

int n,m,k,cnt;
vector<PII> G[SZ];
bool vis[SZ];
ll ans;
struct node{
	int pass,u;
	ll w;
	bool operator < (const node &u) const{return w>u.w;}
};

ll read(){
	ll res=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=(res<<3)+(res<<1)+(c-'0');
		c=getchar();
	}
	return res*f;
}
void prim(){
	priority_queue<node> Q;
	node f;
	f.pass=0,f.u=1,f.w=0;
	Q.push(f);
	while(cnt<n){
		int u=Q.top().u,pass=Q.top().pass;
		ll w=Q.top().w;
		Q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		if(u>n){
			for(int i=0;i<(int) G[u].size();i++){
				int v=G[u][i].fi,w2=G[u][i].se;
				if(!vis[v]){
					f.pass=u,f.u=v,f.w=w+w2;
					Q.push(f);
				}
			}
		}
		else{
			ans+=w;
			cnt++;
			if(pass>n){
				for(int i=0;i<(int)G[pass].size();i++){
					int v=G[pass][i].fi,w2=G[pass][i].se;
					if(!vis[v]){
						f.pass=0,f.u=v,f.w=w2;
						Q.push(f);
					}
				}
			}
			for(int i=0;i<(int) G[u].size();i++){
				int v=G[u][i].fi,w2=G[u][i].se;
				if(!vis[v]){
					f.pass=0,f.u=v,f.w=w2;
					Q.push(f);
				}
			}
			//printf("%lld\n",ans);
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1,u,v,w;i<=m;i++){
		u=read();v=read();w=read();
		G[u].push_back(make_pair(v,w));
		G[v].push_back(make_pair(u,w));
	}
	for(int i=1;i<=k;i++){
		int cost=read();
		for(int j=1,w;j<=n;j++){
			w=read();
			G[j].push_back(make_pair(n+i,w+cost));
			G[n+i].push_back(make_pair(j,w));
		}
	}
	prim();
	printf("%lld",ans);
	return 0;
}

