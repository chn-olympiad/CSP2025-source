#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, j, k, w) for(int (i) = (j); ((w) > 0) ? ((i) <= (k)) : ((i) >= (k)); (i) += (w))
const int N = 2e5;
ll t, n, a[N][4], ans, p, mx[N];
vector<ll> c[4];
ll find(ll x, ll y){
	ll p1 = 0;
	a[x][p1] = -1;
	rep(i, 1, 3, 1){
		if(i == y)continue;
		if(a[x][p1] < a[x][i])p1 = i;
	}
	return p1;
}
bool cmp(ll x, ll y){
	return (a[x][p] - mx[x]) < (a[y][p] - mx[y]);
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		ans = 0;
		rep(i, 1, 3, 1)c[i].clear();
		cin >> n;
		rep(i, 1, n, 1){
			rep(j, 1, 3, 1){
				cin >> a[i][j];
			} 
			c[find(i, 0)].push_back(i);
			ans += a[i][find(i, 0)];
		}
		p = 0;
		rep(i, 1, 3, 1){
			if(c[i].size() > n / 2)p = i;
		}
		if(p == 0)cout << ans << "\n";
		else{
			ll m = c[p].size();
			rep(i, 0, m - 1, 1){
				ll x = c[p][i];
				mx[x] = a[x][find(x, p)];
			}
			sort(c[p].begin(), c[p].end(), cmp);
			m -= n / 2;
			rep(i, 0, m - 1, 1){
				ll x = c[p][i];
				ans -= (a[x][p] - mx[x]); 
			}
			cout << ans << "\n";
		}
	}
	return 0;
}

