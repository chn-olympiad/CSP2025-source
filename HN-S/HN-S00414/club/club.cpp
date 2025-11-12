#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N = 1e5 + 5;
int t, n, a[N][3];
vector<int> v[N];
void solve(){
	cin >> n;
	ll ans = 0;
	for(int i = 1, x, y, z, maxn; i <= n; i++){
		cin >> x >> y >> z;
		maxn = max({x, y, z});
		ans += maxn;
		if(x == maxn){
			v[0].emplace_back(min(x - y, x - z));
		}else if(y == maxn){
			v[1].emplace_back(min(y - x, y - z));
		}else{
			v[2].emplace_back(min(z - x, z - y));
		}
	}
	if(v[0].size() > n / 2){
		sort(v[0].begin(), v[0].end());
		for(int i = 1; i <= v[0].size() - n / 2; i++) 
			ans -= v[0][i - 1];
	}
	if(v[1].size() > n / 2){
		sort(v[1].begin(), v[1].end());
		for(int i = 1; i <= v[1].size() - n / 2; i++) 
			ans -= v[1][i - 1];
	}
	if(v[2].size() > n / 2){
		sort(v[2].begin(), v[2].end());
		for(int i = 1; i <= v[2].size() - n / 2; i++) 
			ans -= v[2][i - 1];
	}
	v[0].clear(), v[1].clear(), v[2].clear() ;
	cout << ans << endl;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> t;
	while(t--) solve();
	return 0;
}
