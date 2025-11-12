#include<bits/stdc++.h>
#define MAXN 100105 
#define ll long long 
int gi(){
	char c;int x=0,f=0;
	while(!isdigit(c=getchar()))f|=(c=='-');
	while(isdigit(c))x=(x*10)+(c^48),c=getchar();
	return f?-x:x;
}
std::mt19937 rnd(std::random_device{}());
#define pr std::pair<int,int>
#define all(x) (x).begin(),(x).end() 
#define mem(x,w) memest(x,w,sizeof(x)) 
#define sz(x) (int)((x).size()) 
#define fi first
#define se second 
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
int n,m,K;
struct E{int u,v,w;}q[2000005],tr[2000005],zj[2000005];
int fa[200105],len,a[15][200005],c[15];
bool vis[15];
ll ans=0,sum=0;
void init(int N){for(int i=1;i<=N;i++)fa[i]=i;}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void mst(){
	std::sort(q+1,q+m+1,[&](E i,E j){return i.w<j.w;});int cnt=0;
	for(int i=1;i<=m;i++){
		int u=q[i].u,v=q[i].v,fu=find(u),fv=find(v);
		if(fu==fv)continue;
		fa[fu]=fv,++cnt,sum+=q[i].w;
		tr[++len]=q[i];
		if(cnt==n-1)break;
	}
}
ll calc(){
	int lz=0,os=0;ll res=0;
	for(int i=1;i<=len;i++)zj[++lz]=tr[i];
	for(int i=1;i<=K;i++)
		if(vis[i]){
			for(int j=1;j<=n;j++)zj[++lz]=(E){i+n,j,a[i][j]};
			res+=c[i];++os;
		}
	std::sort(zj+1,zj+lz+1,[&](E i,E j){return i.w<j.w;});
	init(n+K);int cnt=0;
	for(int i=1;i<=lz;i++){
		int u=zj[i].u,v=zj[i].v,fu=find(u),fv=find(v);
		if(fu==fv)continue;
		fa[fu]=fv;res+=zj[i].w;++cnt;
		if(cnt==n+os-1)break;
	}
	return res;
}
void dfs(int x){
	if(x==K+1)return;
	vis[x]=1;
	ll tmp=calc();cnk(ans,tmp);
	dfs(x+1);
	vis[x]=0;
	tmp=calc();cnk(ans,tmp);
	dfs(x+1);
}
int main(){
	freopen("road.in","r",stdin),freopen("bf.out","w",stdout);
	n=gi(),m=gi(),K=gi();init(n);
	for(int i=1;i<=m;i++)q[i].u=gi(),q[i].v=gi(),q[i].w=gi();
	for(int i=1;i<=K;i++){
		c[i]=gi();
		for(int j=1;j<=n;j++)a[i][j]=gi();
	}
	mst();ans=sum;
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}

