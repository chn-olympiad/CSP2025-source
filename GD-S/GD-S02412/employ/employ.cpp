#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
ll n, m, pa[510], idx = 0;
string df;
ll mark[510] = {0};
ll bfs(ll f, ll p){
	ll ans = 0;
	if(f >= n && p <= n - m){
		return 1;
	}
	else if(f >= n && p > n - m) return 0;
	else if(p > n - m) return 0;
	for(ll i = 1; i <= n; i++){
		if(mark[i] != 0) continue;
		if(df[f] = '0'){
			mark[i] = -1;
			++p;
			ll iidx = idx, pp = p;
			while(p >= pa[idx]){
				idx++;
				p++;
			}
			ans += bfs(f + 1, p);
			ans %= MOD;
			p = pp; 
			idx = iidx;
		}
		if(df[f] = '1'){
			ans += bfs(f + 1, p);
			ans %= MOD;
		}
	}
	return ans;
}
bool cmp(ll x, ll y){
	return x < y;
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	string ls;
	cin >> ls;
	df = "0" + ls;
	for(ll i = 1; i <= n; i++) cin >> pa[i];
	pa[0] = n;
	sort(pa + 1, pa + 1 + n, cmp);
	cout << bfs(0, 0);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

