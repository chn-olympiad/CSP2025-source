#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,nxt;
	long long w;
}e[22000007];
int h[11004],cnt;
void add(int u,int v,long long w){
	e[++cnt].nxt=h[u];
	h[u]=cnt;
	e[cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
}
int n,m,k;
long long c[11004];
int fa[110004];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(int u,int v){
	if(find(u)==find(v))return;
	fa[fa[u]]=fa[v];
	return;
}
void init(){
	scanf("%d%d%d",&n,&m,&k);
	int u,v;
	long long w;
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&w);
			add(j,n+i,w+c[i]);
			add(n+i,j,w+c[i]);
		}
	}
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	return;
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int ct[50];
long long su[50];
void work(){
	sort(e+1,e+1+cnt,cmp);
	int u,v,w;
	long long ans=0;
	for(int i=1;i<=cnt;i++){
		u=e[i].u;
		v=e[i].v;
		w=e[i].w;
		if(find(u)!=find(v)){
			merge(u,v);
			ans+=w;
			if(u<v)swap(u,v);
			if(u>n){
				ct[u-n]++;
				su[u-n]+=w;
			}
		}
	}
	for(int i=1;i<=k;i++){
		if(ct[i]==1){
			ans-=su[i];
		}else if(ct[i]>1){
			ans-=c[i]*(ct[i]-1);
		}
	}
	printf("%lld",ans);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int t;
	//~ scanf("%d",&t);
	t=1;
	while(t--){
		init();
		work();
	}
	return 0;
}
