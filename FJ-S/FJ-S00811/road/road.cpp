#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#define int long long
using namespace std;
const int N=10050;
const int M=10;
const int INF=2e18;
struct node{
	int to,w;
	node(){};
	node(int to,int w){
		this->to=to;
		this->w=w;
	}
};
struct pk{
	int to,w;
	pk(){};
	pk(int to,int w){
		this->to=to;
		this->w=w;
	}
	operator <(const pk &tt)const{
		return this->w>tt.w;
	}
};
vector<node>G[N+5];
vector<node>G2[N+5];
priority_queue<pk>q;
int a[M+5][N+5],c[M+5];
int vis[N+5];
int mind[N+5];
int nn,m,k;
inline void add(int u,int v,int w){
	G[u].push_back(node(v,w));
	G[v].push_back(node(u,w));
}
inline void add2(int u,int v,int w){
	G2[u].push_back(node(v,w));
	G2[v].push_back(node(u,w));
}
inline bool update(int to,int w){
	if(w<mind[to])return mind[to]=w,true;
	return false;
}
inline int solve(int n){
	for(int i=1;i<=n+M;i++)mind[i]=INF;
	for(int i=1;i<=n+M;i++)vis[i]=0;
	while(q.size())q.pop();
	int cnt=1;
	vis[1]=1;
	for(node u:G[1]){
		if(update(u.to,u.w))q.push(pk(u.to,u.w));
	}
	for(node u:G2[1]){
		if(update(u.to,u.w))q.push(pk(u.to,u.w));
	}
	int res=0;
	while(cnt<n){
		cnt++;
		int flag=1;pk t;
		while(flag){
			t=q.top();
			if(!vis[t.to])flag=0;
			q.pop();
		}
		res+=t.w,vis[t.to]=1;
		for(node u:G[t.to]){
			if(vis[u.to])continue;
			if(update(u.to,u.w))q.push(pk(u.to,u.w));
		}
		for(node u:G2[t.to]){
			if(vis[u.to])continue;
			if(update(u.to,u.w))q.push(pk(u.to,u.w));
		}
	}
	return res;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>nn>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",c+i);
		for(int j=1;j<=nn;j++)scanf("%lld",&a[i][j]);
	}
	int ans=INF;
	for(int P=0;P<(1<<k);P++){
		for(int i=1;i<=nn+k;i++)G2[i].clear();
		int now=0,nc=0;
		for(int j=1;j<=k;j++){
			if((P>>(j-1))&1){
				now+=c[j],nc++;
				for(int i=1;i<=nn;i++)add2(nn+j,i,a[j][i]);
			}
		}
		int r=now+solve(nn+nc);
		ans=min(ans,r);
	}
	cout<<ans;
}
