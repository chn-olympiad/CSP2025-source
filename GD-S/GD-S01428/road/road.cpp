#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define fi first
#define se second
using namespace std;
template<typename T> inline void read(T &x){
	x=0;
	T w=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') w=-1;
		c=getchar();
	}
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	x*=w;
}
template<typename T> inline void write(T x){
	if(x<0) putchar('-'),x=(~x)+1;
	if(x>9) write(x/10);
	putchar(x%10^48);
}
const ll N=1e4+10,M=1e6+10,inf=1e16;
struct edge{
	ll u,v,w;
}e[(M<<1)+(N<<4)],e1[(N<<4)];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
ll f[N<<1];
ll n,m,k,nbs;
ll val[15][N];
ll ans;
ll t[15],cnt;
bool tag[M];
vector<ll>v[N];
ll fin(ll x){
	return f[x]==x ? x : f[x]=fin(f[x]);
}
ll creat(ll bs,bool type,ll pt){
	ll sum=0,ans=0;
	for(int i=1;i<=bs;i++){
		ll x=fin(e[i].u),y=fin(e[i].v);
		if(x!=y){
			f[x]=y;
			ans+=e[i].w;
			tag[i]=type;
			sum++;
		}
		if(sum==pt-1) break;
	}
	return ans;
}
void dfs(ll pos){
	if(pos>k){
		if(!pos) return ;
		ll g=nbs,sum=0;
		for(int i=1;i<=nbs;i++){
			e[i]=e1[i];
		}
		for(int i=1;i<=cnt;i++){
			sum+=val[t[i]][0];
			for(int j=1;j<=n;j++){
				e[++g]=(edge){n+i,j,val[t[i]][j]};
			}
		}
		for(int i=1;i<=n+cnt;i++) f[i]=i;
		sort(e+1,e+g+1,cmp);
		ans=min(ans,sum+creat(nbs+cnt*n,0,n+cnt));
		return ;
	}
	t[++cnt]=pos;
	dfs(pos+1);
	cnt--;
	dfs(pos+1);
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	read(n),read(m),read(k);
	for(int i=1;i<=m;i++){
		read(e[i].u),read(e[i].v),read(e[i].w);
	}
	for(int i=1;i<=k;i++){
		read(val[i][0]);
		for(int j=1;j<=n;j++) read(val[i][j]);
	}
	for(int i=1;i<=n;i++) f[i]=i;
	sort(e+1,e+m+1,cmp);
	ans=creat(m,1,n);
	for(int i=1;i<=m;i++){
		if(tag[i]) e1[++nbs]=e[i];
	}
//	cout<<ans<<'\n';
	dfs(1);
	write(ans);
	return 0;
}
/*
冷静一点。 

假设没有新点，显然答案为最小生成树

考虑加入新点的操作 

首先不管如何，加入新点后原来的边肯定还是最小生成树上的

考虑kruskal重构树
 
删lca

最终的最优方案一定是kruskal重构树上删点的方案 

状压怎么做？？？

wocnm zhe tm 2^20

只允许一个相交

贪心：

1.每个点最多只被1个乡镇删掉 


*/
