#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+15;
int n,m,k,a[15][MAXN],u,v;
long long c[MAXN],dis[MAXN],ans,w;
template <typename T>inline void read(T &x) {
	x=0;
	int f=1;
	char s=getchar();
	while(!isdigit(s)) {
		if(s=='-')f=-1;
		s=getchar();
	}
	while(isdigit(s)) {
		x=x*10+s-'0';
		s=getchar();
	}
	x*=f;
}
struct node{
	int to;
	long long w;
	node(){
	}
	node(int a,long long b){
		to=a,w=b;
	}
	bool operator<(const node x)const{
		return w<x.w;
	}
}x;
vector<node>e[MAXN];
bool vis[MAXN],add[MAXN];
priority_queue<node>q;
void solve(){
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	q.push({1,0});
	while(!q.empty()){
//		puts("1");
		x=q.top();
		q.pop();
		if(vis[x.to])continue;
		vis[x.to]=1;ans=max(ans,x.w);
		bool flag=1;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				flag=0;
				break;
			}
		}
		if(flag)break;
		int l=e[x.to].size();
		for(int i=0;i<l;i++){
			if(!vis[e[x.to][i].to]){
				if(dis[e[x.to][i].to]>x.w+e[x.to][i].w){
					dis[e[x.to][i].to]=x.w+e[x.to][i].w;
					q.push({e[x.to][i].to,dis[e[x.to][i].to]});
				}
			}
		}
//		for(int i=1;i<=k;i++){
//			if(!vis[n+i]){
//				if(dis[n+i]>x.w+a[i][x.to]){
//					dis[n+i]=x.w+a[i][x.to];
//					q.push({n+i,dis[i+n]});
//				}
//			}
//		}
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				if(!vis[j]&&dis[j]>(!add[i])*c[i]+a[i][j]+a[i][x.to]){
					dis[j]=(!add[i])*c[i]+a[i][j]+a[i][x.to];
					add[i]=1;
					q.push({j,dis[j]});
				}
			}
		}
	}
	for(int i=1;i<=k;i++){
		if(add[i])ans+=c[i];
	} 
}
int main(){
	#ifndef NOT_FRE
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	#endif
	read(n),read(m),read(k);
	for(int i=1;i<=m;i++){
		read(u),read(v),read(w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		read(c[i]);
		for(int j=1;j<=n;j++)read(a[i][j]);
	}
	solve();
	printf("%lld",ans);
	return 0;
}
