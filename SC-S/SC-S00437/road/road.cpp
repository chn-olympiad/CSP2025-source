#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5,M=1e6+5,K=12;
struct node{
	int u,v;
	ll w;
}e[M],tree[N],h[N*(K+1)];
int n,m,k,cnt=0,top=0,tot=0;
ll ans=0;
int sta[K];
ll c[K],a[K][N];
int fa[N],rt[N+K];
bool cmp(const node &xi,const node &yi){
	return xi.w<yi.w;
}
int find(int x){
	if(fa[x]!=x)  fa[x]=find(fa[x]);
	return fa[x];
}
void getedge(){
	for(int i=1;i<=n;++i)  fa[i]=i;
	int t=0;
	ll res=0;
	for(int i=1;i<=m;++i){
		int uf=find(e[i].u);
		int vf=find(e[i].v);
		if(uf!=vf){
			tree[++cnt]=e[i];
			res+=e[i].w;
			t++;
			fa[vf]=uf;
			if(t==n-1)  break;
		}
	}
	ans=res;
}
int find_rt(int x){
	if(rt[x]!=x)  rt[x]=find_rt(rt[x]);
	return rt[x];
}
ll kruskal(int po){
	sort(h+1,h+tot+1,cmp);
	int t=0;
	ll res=0;
	for(int i=1;i<=n+k;++i)  rt[i]=i;
	for(int i=1;i<=tot;++i){
		int uf=find_rt(h[i].u);
		int vf=find_rt(h[i].v);
		if(uf!=vf){
			res+=h[i].w;
			t++;
			rt[vf]=uf;
			if(t==po-1)  break;
		}
	}
	return res;
}
void dfs(int pos,ll sum){
	if(pos>k){
		if(top==0)  return;
		tot=cnt;
		for(int i=1;i<=cnt;++i)
		  h[i]=tree[i];
		for(int i=1;i<=top;++i){
			int ui=sta[i];
			for(int j=1;j<=n;++j){
				int vi=j;
				ll wi=a[ui-n][j];
				h[++tot]=(node){ui,vi,wi};
			}
		}
		ans=min(ans,kruskal(n+top)+sum);
		return;
	}
	sta[++top]=pos+n;
	dfs(pos+1,sum+c[pos]);
	sta[top]=0;
	--top;
	dfs(pos+1,sum);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
	  scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
	sort(e+1,e+m+1,cmp);
	getedge();
	for(int i=1;i<=k;++i){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;++j)
		  scanf("%lld",&a[i][j]);
	}
	dfs(1,0);
	printf("%lld\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/