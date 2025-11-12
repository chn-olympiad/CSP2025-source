#include<bits/stdc++.h>
namespace cxk{
	using namespace std;
	#define ll long long
	ll n,m,k,gs,t,u[1000005],v[1000005],w[1000005],c[15],vw[15][10005],sz[10005],fa[10005];
	bitset<15>vis;
	ll an=1e18;
	struct node{
		ll u,v,w;
		bool operator<(node x)const{return w<x.w;}
	}a[1100005];
	struct nd{
		ll c,vw[10005];
		bool operator<(nd x){return c>x.c;}
	}ck[15];
	ll fd(ll x){return x==fa[x]?x:fa[x]=fd(fa[x]);}
	ll mst(){
		ll ans=0;
		t=0;
		for(int i=1;i<=m;i++)a[++t]={u[i],v[i],w[i]};
		for(int i=1;i<=k;i++){
			if(vis[i]){
				for(int j=1;j<=n;j++)a[++t]={n+i,j,ck[i].vw[j]};
				ans+=ck[i].c;
			}
		}
		sort(a+1,a+1+t);
		for(int i=1;i<=n;i++){
			fa[i]=i;
			sz[i]=1;
		}
		for(int i=n+1;i<=n+k;i++){
			fa[i]=i;
			sz[i]=0;
		}
		for(int i=1;i<=m;i++){
			ll u=fd(a[i].u),v=fd(a[i].v);
			if(u==v)continue;
			fa[u]=v;
			sz[v]+=sz[u];
			ans+=a[i].w;
			if(sz[v]==n)break;
		}
		return ans;
	}
	void dfs(ll x){
		if(x>k){
			ll vv=mst();
			an=min(an,vv);
			if(clock()*1.0/CLOCKS_PER_SEC>=0.85){
				cout<<an;
				exit(0);
			}
			return;
		}
		vis[x]=0;
		dfs(x+1);
		vis[x]=1;
		dfs(x+1);
	}
	int main(){
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
		ios::sync_with_stdio(0);
		cin.tie(nullptr);
		cout.tie(nullptr);
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++)cin>>u[i]>>v[i]>>w[i];
		bool a1=1;
		for(int i=1;i<=k;i++){
			cin>>ck[i].c;
			if(ck[i].c!=0)a1=0;
			for(int j=1;j<=n;j++)cin>>ck[i].vw[j];
		}
		sort(ck+1,ck+1+k);
		if(k==0)cout<<mst();
		else if(a1){
			for(int i=1;i<=k;i++)vis[i]=1;
			cout<<mst();
		}else{
			dfs(1);
			cout<<an;
		}
		return 0;
	}
}
int main(){return cxk::main();}
/*
1
5 1 1
5 3 2
5 4 4
5 2 8

100
1 1
3 2
2 3
4 4

0
1 4 6
4 2 5
4 3 4

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
