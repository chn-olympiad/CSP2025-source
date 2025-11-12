#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e4+5;
ll n, m, k, G[N][N], c[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    vector<ll> q;
    for(int i=0; i<m; ++i){
		int u,v,w;
		cin >> u >> v >> w;
		G[u][v]=w;
		G[v][u]=w;
		q.push_back(w);
	}
	if(k==0) {
		sort(q.begin(),q.end());
		ll ans=0;
		for(int i=0; i<n-1; ++i) ans+=q[i];
		cout << ans;
		return 0;
	}
	for(int i=1; i<=k; ++i){
		cin >> c[i];
		ll a[N];
		for(int j=1; j<=n; ++j){
			cin >> a[j];
		}
		for(int j=1; j<=n; ++j){
			for(int l=j+1; l<=n; ++l){
				ll hf=a[j]+a[l];
				if(hf<G[j][l]) {
					G[j][l]=hf;
					G[l][j]=hf;
					
				}
			}
		}
	}
	q.clear();
	for(int i=1; i<=n; ++i){
		for(int j=i+1; j<=n; ++j){
			if(G[i][j]!=0) q.push_back(G[i][j]);
		}
	}
	sort(q.begin(), q.end());
	ll ans=0;
	for(int i=0; i<n-1; ++i) {
		ans+=q[i]; }
	cout << ans;
    return 0;
}
