#include<bits/stdc++.h>
#define ll long long
#define INF 1e16
using namespace std;
const int N=1e4+20,M=1e6+10,MM=2e5+10,MK=20;
struct node{
	int u,v,w;
}ed[M];
struct Node{
	int u,v,w;
}e[MM];
bool cmp(node a,node b){
	return a.w<b.w;
}
bool Cmp(Node a,Node b){
	return a.w<b.w;
}
int fa[N],c[MK];
int read(){
	int ans=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans;
}
int fnd(int x){
	if(x==fa[x]){
		return x;
	}
	return fa[x]=fnd(fa[x]);
}
int sum,m,n,K,Sum;
void add(int u,int v,int w){
	e[++m]=(Node){u,v,w};
}
void Mer(node x){
	int u=x.u,v=x.v,w=x.w;
	int fu=fnd(u),fv=fnd(v);
	if(fu!=fv){
		fa[fu]=fv;
		sum++;
		add(u,v,w);
	}
}
ll minn=INF,S;
bool vis[MK];
void Mer2(Node x){
	int u=x.u,v=x.v,w=x.w;
	if(u>n){
		if(!vis[u-n]){
			return;
		}
	}
	int fu=fnd(u),fv=fnd(v);
	if(fu!=fv){
		fa[fu]=fv;
		Sum++;
		S+=w;
	}
}
void dfs(int t){
	if(t==K+1){
		for(int i=1;i<=n+K;i++){
			fa[i]=i;
		}
		Sum=0,S=0;
		int tt=0;
		for(int i=1;i<=K;i++){
			if(vis[i]){
				S+=c[i];
				tt++;
			}
		}
		for(int i=1;i<=m;i++){
			if(Sum==n+tt-1){
				break;
			}
			Mer2(e[i]);
		}
		minn=min(minn,S);
		return;
	}
	vis[t]=1;
	dfs(t+1);
	vis[t]=0;
	dfs(t+1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m1;
	n=read(),m1=read(),K=read();
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m1;i++){
		ed[i].u=read(),ed[i].v=read(),ed[i].w=read();
	}
	sort(ed+1,ed+1+m1,cmp);
	for(int i=1;i<=m1;i++){
		if(sum==n-1){
			break;
		}
		Mer(ed[i]);
	}
	for(int i=1;i<=K;i++){
		c[i]=read();
		for(int j=1,w;j<=n;j++){
			w=read();
			add(n+i,j,w);
		}
	}
	sort(e+1,e+1+m,Cmp);
	dfs(1);
	printf("%lld\n",minn);
	return 0;
}
