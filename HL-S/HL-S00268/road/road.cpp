#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int >
#define plp pair<ll,pii >
const int N=1e4+1000,M=1e6+1000;
struct KKK{
	ll w;
	int u,v;
}R[M],K[M],T[M];
bool cmp(KKK x,KKK y){
	return x.w<y.w;
}
ll ans=1e18,a[15][N],c[15];
int tot,n,m,k,fa[N];
int fd(int p){
	if(fa[p]==p)
		return p;
	return fa[p]=fd(fa[p]);
}
ll krus(ll ans,int cnt){
	
	sort(T+1,T+1+cnt*n,cmp);
	int h1=1,h2=1,tot=0;
	while(tot<n+cnt-1){
		ll va;	int x,y;
		if(h1<=m&&h2<=cnt*n){
			if(R[h1].w<T[h2].w){	x=R[h1].u;	y=R[h1].v;	va=R[h1].w;	h1++;}
			else{					x=T[h2].u;	y=T[h2].v;	va=T[h2].w;	h2++;}
		}
		else{
			if(h1<=m){	x=R[h1].u;	y=R[h1].v;	va=R[h1].w;	h1++;}
			else{		x=T[h2].u;	y=T[h2].v;	va=T[h2].w;	h2++;}
		}		
		if(fd(x)!=fd(y)){
			tot++;
			ans+=va;
			fa[fd(x)]=fd(y);
		}
	}
	return ans;
}
void dfs(int dep,int t,int cnt){
	if(dep>k){
		for(int i=1;i<=cnt*n;i++)
			T[i]=K[i];
		for(int i=1;i<=n+cnt;i++)	
			fa[i]=i;
		ans=min(ans,krus(t,cnt));
		return ;
	}
	dfs(dep+1,t,cnt);
	ll u=dep;
	for(int i=1;i<=n;i++){
		K[i+cnt*n].u=n+cnt+1;
		K[i+cnt*n].v=i;
		K[i+cnt*n].w=a[dep][i];	
	}
	dfs(dep+1,t+c[dep],cnt+1);
	return ;
}
int main(){	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		scanf("%d%d%lld",&R[i].u,&R[i].v,&R[i].w);
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%lld",&a[i][j]);
	}
	sort(R+1,R+1+m,cmp);
	dfs(1,0,0);
	cout<<ans;
	return 0;
}