#include<bits/stdc++.h>
#define all(op) op.begin(),op.end() 
using namespace std;
using ll=long long;
const int inf=1e9+7,N=1e4+1000;
const ll INF=1e18+7;
struct node{
	int u,v,w;
};
int fa[N],sum[N];
int find(int x){return (fa[x]==x)?x:(find(fa[x]));}
void merge(int u,int v){
	auto fu=find(u),fv=find(v);
	if(fu==fv)return;
	if(sum[fv]>sum[fu])swap(fu,fv);
	sum[fu]+=sum[fv];
	fa[fv]=fu;
}
void solve(){
	int n,m,k;cin>>n>>m>>k;
	vector<node> e(m+1); 
	vector<int> a(k+1);
	vector<vector<node>> c(k+1,vector<node>(n)); 
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		cin>>a[i];
		for(int j=0;j<n;j++){
			int u;cin>>u;
			c[i][j]={i+n,j+1,u};
		}
	}
	
	auto calc=[&](int sm,vector<node> h)->ll {
		ll ans=0;
		iota(fa,fa+N,0);
		fill(sum,sum+N,1);
		sort(h.begin()+1,h.end(),[&](node x,node y){
			return x.w<y.w;
		});	
		for(int i=1;i<=sm;i++){
			auto fu=find(h[i].u),fv=find(h[i].v);
			if(fu==fv)continue;
			ans+=h[i].w;
			merge(fu,fv); 
		}
//		cerr<<ans<<"\n";
		return ans;
	};
	
	ll minn=INF;
	for(int i=0;i<(1<<k);i++){
//		cerr<<i<<"--------\n";
		vector<int> p;
		ll res=0;
		for(int j=0;j<k;j++)if(i&(1<<j))p.push_back(j+1);
		
		vector<node> h=e;
		for(auto u:p){
			res+=a[u];
			for(auto v:c[u])h.push_back({v.u,v.v,v.w});
		}
		
//		for(auto u:h)cerr<<u.u<<" "<<u.v<<" "<<u.w<<"\n";
		
		minn=min(minn,calc((int)h.size()-1,h)+res);
//		cerr<<minn<<"\n";
	}
	cout<<minn;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
//    freopen("road2.in","r",stdin);
//    freopen("test.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T=1;
//     cin>>T;
    while(T--)solve();
}
/*

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4


13

*/
