#include <bits/stdc++.h>
#define ll long long 

using namespace std;
const int N = 1e6+5+2e5;
inline ll read(){
	ll sg=1,x=0;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')sg=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return sg*x;
}
//跑完后只需检查出编号，是不是只连了cj/a_(j,i)
int n,m,k;
ll c[25];//乡镇的入编号n+1~n+k 出编号 n+k+1~n+2k
struct Edge{
	int v,nxt;
	ll w;
	bool used;
}E[N<<1];
#define fore(i,pos) for(int i=head[pos]; i; i=E[i].nxt)
int head[N],cntEdge=1;
void add(int u,int v,ll w){
	E[++cntEdge]={v,head[u],w,0};
	head[u]=cntEdge;
}
struct node{
	int p;
	ll dis;
	int eid;
	bool operator<(const node oth)const {
		return dis>oth.dis;
	}
};
bool vis[N];
bool us[N];
ll ans,cnt;
void prim(){
	priority_queue<node> q;
	for(int i=1; i<=k; ++i){
		q.push({n+i,c[i],0});
	}
	q.push({1,0,0});
	while(!q.empty()){
		node p=q.top();
		q.pop();
		if(vis[p.p])continue;
		vis[p.p]=1;
		if(p.p<=n)++cnt;
		ans+=p.dis;
		if(p.p>n)us[p.p]=1;
		if(p.eid!=0)us[p.eid]=0;
		if(cnt>=n)return;
		fore(i,p.p){
			int vi=E[i].v;
			ll wi=E[i].w;
			if(vis[vi])continue;
			int nid=(p.p>n?p.p-n:0);
			q.push({vi,wi,nid});
		}
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	ll wi;
	for(int i=1,ui,vi; i<=m; ++i){
		ui=read(),vi=read(),wi=read();
		add(ui,vi,wi);
		add(vi,ui,wi);
	}
	for(int i=1; i<=k; ++i){
		c[i]=read();
		for(int j=1; j<=n; ++j){
			wi=read();
			add(n+i,j,wi);
		}
	}
	prim();
	for(int i=1; i<=k; ++i){
		if(us[i])ans-=c[i];
	}
	printf("%lld",ans);
	return 0;
}