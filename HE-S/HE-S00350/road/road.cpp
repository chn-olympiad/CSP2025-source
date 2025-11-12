#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll K=15,N=5e6+10;

ll n,m,k,ans=0x3f3f3f3f3f;
ll c[K],a[K][K],fa[N];
vector<ll> vl;

struct node{
	
	ll u,v,w;
}e[N],org[N];

inline ll find(ll x){
	
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

inline void merge(ll x,ll y){
	
	fa[find(x)]=find(y);
}

inline bool cmp(node a,node b){
	
	return a.w<b.w;
}

inline void kruskal(vector<ll> vl){
	
	for(int i=1;i<=n+vl.size();i++) fa[i]=i;
	
	ll cnt=0,op=1;
	for(auto id:vl){
		
		for(int i=1;i<=n;i++){
			
			e[op+m].u=id+n,e[op+m].v=i,
			e[op+m].w=a[id][i];
			
			op++;
		}
		
		cnt+=c[id];
	}
	
	for(int i=1;i<=m;i++) e[i]=org[i];
	sort(e+1,e+m+op,cmp);
	
	ll tot=0;
	for(int i=1;i<m+op;i++){
		
		ll x=e[i].u,y=e[i].v,cst=e[i].w;
		
		if(find(x)==find(y)) continue;
		
		merge(x,y);
		tot++;
		cnt+=cst;
		
		if(tot==n+vl.size()-1) break;
	}
	
	ans=min(ans,cnt);
	
	return;
}

inline void dfs(ll step){
	
	if(step>k){
		
		kruskal(vl);
		return;
	}
	
	vl.push_back(step);
	dfs(step+1);
	
	vl.pop_back();
	dfs(step+1);
	
	return;
}

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	//先打暴力。
	//考虑 2^k 枚举状态，再 O (m log m) 求最小生成树。 
	//期望分数：32 pts

	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>org[i].u>>org[i].v>>org[i].w;
	for(int i=1;i<=k;i++){
		
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	
	dfs(1);
	
	cout<<ans<<'\n';
	
	return 0;
}
/*

	{16} 2,3,4,7,6,5,1,3,2,8,6,7,78,,
	{64} 1h[8:1]/2,3,4,5,6,7,,,,,,,,,,,
	{64} 8h[8:1]/7,6,5,4,3,2,,,,,,,,,,,,,,,,,,,,,,,,,,,
	{16} 2,4,3,7,5,6,1,4,3,8,5,6,1,3,2,8,6,7,2,4,3,7,5,6,1,4,3,8,5,6,1,3,2,8,6,7,
	{32} 1,2,3,,8,7,6,,2,3,4,,7,6,5,,
	{64} 1,2,3,4,5,6,7,8,
	{4} 1-6[16:1]/2-6[16:1],1-4[16:1]/2-4[16:1],1w5[16:1],1b,
	E

*/
