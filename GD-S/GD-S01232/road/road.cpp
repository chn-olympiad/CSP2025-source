#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
typedef long long ll;
ll n,m,k,vn;
ll h[N],pre[N],w[N],nxt[N],idx;
ll f[N],c[N],ans,x,y,z,num,mans=INT_MAX;
ll kp[20][N];
struct nd{
	ll x,y,z;
	bool operator<(const nd&b)const{return z<b.z;}
}v[N];
void add(ll x,ll y,ll z){
	h[++idx]=y;
	nxt[idx]=pre[x];
	w[pre[x]=idx]=z; 
}
ll find(ll x){return f[x]==x?x:f[x]=find(f[x]);}
void merge(ll x,ll y){f[find(x)]=f[find(y)];}
void kruskal(ll u,ll m,ll n){
	sort(v+1,v+1+m),ans=num=0;
	for(ll i=1;i<=n;++i)f[i]=i;
	for(ll i=1;i<=m;++i){
		if(find(v[i].x)==find(v[i].y))continue;
		if(v[i].x<=vn&&v[i].y<=vn)++num;
		else{
			if(v[i].x<=vn&&find(v[i].x)==v[i].x&&find(v[i].y)!=v[i].y)++num;//y->new x,x<=vn
			else if(v[i].y<=vn&&find(v[i].y)==v[i].y&&find(v[i].x)!=v[i].x)++num;//x->new y,y<=vn
		}
		ans+=v[i].z,merge(v[i].x,v[i].y);
		if(num==n-1)break;
	}
	if(num==n-1)mans=min(mans,ans+u);
}
void dfs(ll p,ll u,ll m,ll n){
	if(p>k)return kruskal(u,m,n),void();
	dfs(p+1,u,m,n);
	for(ll i=1;i<=vn;++i)v[++m]={n+1,i,kp[p][i]};
	dfs(p+1,u+c[p],m,n+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k,vn=n;
	if(k==0){
		for(ll i=1;i<=n;++i)f[i]=i;
		for(ll i=1;i<=m;++i)cin>>v[i].x>>v[i].y>>v[i].z;
		sort(v+1,v+1+m);
		for(ll i=1;i<=m;++i){
			if(find(v[i].x)==find(v[i].y))continue;
			++num,ans+=v[i].z,merge(v[i].x,v[i].y);
			if(num==n-1)break;
		}
		cout<<ans<<endl;
	}else{
		for(ll i=1;i<=n;++i)f[i]=i;
		for(ll i=1;i<=m;++i)cin>>v[i].x>>v[i].y>>v[i].z;
		for(ll i=1;i<=k;++i){
			cin>>c[i];
			for(ll j=1;j<=n;++j)cin>>kp[i][j];
		}
//		kruskal();
		dfs(1,0,m,n);
		cout<<mans<<endl;
	}
	return 0;
}
/*
7 10 0
1 3 1
3 6 1
6 5 1
6 7 1
5 2 1
5 4 1
1 2 999
2 3 999
2 4 999
3 7 3
*/
