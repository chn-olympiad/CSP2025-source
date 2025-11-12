#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+20;
long long n,m,a[11][maxn],vis[maxn],k,c[11],ans=0;
bool tag[maxn][maxn];
struct st{
	long long u,v,w;
	bool operator<(const st &rt)const{
		return w>rt.w;
	};
};
struct Node{
	long long v,w;
};
priority_queue<st> fe;
vector<Node> e[maxn];
void f(){
	int p=1;
	vis[1]=1;
	vis[0]=1;
	for(int i=0;i<e[p].size();i++){
		fe.push({p,e[p][i].v,e[p][i].w});
	}
	while(!fe.empty()&&vis[0]<n){
		st q=fe.top();
		fe.pop();
		if(vis[q.u]&&vis[q.v]) continue;
		vis[q.u]=1;vis[q.v]=1;
		if(q.v<=n) vis[0]++;
		ans+=q.w;
		if(q.u>n) ans-=c[q.u-n];
		p=q.v;
		for(int i=0;i<e[p].size();i++){
			if(vis[e[p][i].v]) continue;
			fe.push({p,e[p][i].v,e[p][i].w});
		}	
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		long long u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
			e[n+i].push_back({j,a[i][j]+c[i]});
			e[j].push_back({n+i,a[i][j]+c[i]});
		}
	}
	f();
	cout<<ans<<endl;
}

