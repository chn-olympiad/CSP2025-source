#include<bits/stdc++.h>
using namespace std;
#define V vector
#define int long long
#define ull unsigned long long
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define pb push_back
#define lb(x) (x)&(-x)
const int INF=1e9+10;
struct node{
	int u,v,w;
	friend bool operator <(const node &a,const node &b){
		return a.w<b.w;
	}
};
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m,k;cin>>n>>m>>k;
	V<int>fa(n+k+1);iota(fa.begin(),fa.end(),0);
	V<V<int> >val(k);
	auto fin=[&](int x){
		while(x^(fa[x])) x=fa[x]=fa[fa[x]];
		return x;
	};
	V<node>e(m);
	V<node>ne;
	FOR(i,0,m-1){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	int ans=0,tot=0;
	sort(e.begin(),e.end());
	FOR(i,0,m-1){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(fin(u)!=fin(v)){
			fa[fin(u)]=fin(v);
			ans+=w;
			tot++;
		}
		if(tot==n-1) break;
	}
	FOR(i,0,k-1){
		int x;
		FOR(j,1,n+1){
			cin>>x;
			val[i].pb(x);
		}
	}
	if(k<=5){
		for(int i=1;i<(1<<k);i++){
			int x=i,tim=0;
			int ans1=0,tot1=0;
			ne=e;
//			cout<<i<<"\n";
			while(x){
				int u=lb(x);x-=lb(x);tim++;
				u=log2(u);ans1+=val[u][0];
//				cout<<"u: "<<u<<"\n";
				FOR(j,1,n) ne.pb({n+u+1,j,val[u][j]});
			}
//			cout<<"----"<<ans1<<"\n";
			if(ans1>=ans) continue;
			iota(fa.begin(),fa.end(),0);
			sort(ne.begin(),ne.end());
			FOR(i,0,ne.size()-1){
				int u=ne[i].u,v=ne[i].v,w=ne[i].w;
				if(fin(u)!=fin(v)){
					ans1+=w;
					fa[fin(u)]=fin(v);
					tot1++;
				}
				if(tot1==tim-1) break;
			}
			ans=min(ans,ans1);
		}
		cout<<ans;
	}else cout<<ans;
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
