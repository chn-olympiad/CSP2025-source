#include <bits/stdc++.h>
//#define int long long
#define rep(x, y, z) for(int x = (int)(y);x <= (int)(z);x++)
#define per(x, y, z) for(int x = (int)(y);x >= (int)(z);x--)
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
typedef long long ll;
using namespace std;
const int N = 1e5 + 5, inf = 0x3f3f3f3f;
int n;
pii a[N][4];
bool cmp(pii x, pii y){
	return x.fi > y.fi;
}
void solve(){
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d%d%d", &a[i][1].fi, &a[i][2].fi, &a[i][3].fi);
	rep(i, 1, n) rep(j, 1, 3) a[i][j].se = j;
	rep(i, 1, n) sort(a[i] + 1, a[i] + 4, cmp);
	vector<int> vec1, vec2, vec3;
	ll ans = 0;
	rep(i, 1, n){
		ans += a[i][1].fi;
		if(a[i][1].se == 1) vec1.pb(i);
		else if(a[i][1].se == 2) vec2.pb(i);
		else vec3.pb(i);
	}
	int val = -1, pos = -1, lim = (n >> 1);
	if((int)vec1.size() > lim) val = 1, pos = vec1.size() - lim;
	else if((int)vec2.size() > lim) val = 2, pos = vec2.size() - lim;
	else if((int)vec3.size() > lim) val = 3, pos = vec3.size() - lim;
	else{
		printf("%lld\n", ans);
		return;
	}
	vector<int> vec;
	rep(i, 1, n) if(a[i][1].se == val) vec.pb(a[i][1].fi - a[i][2].fi);
	sort(vec.begin(), vec.end());
	rep(i, 0, pos - 1) ans -= vec[i];
	printf("%lld\n", ans);
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = 1;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}
// 什么时候这种题也能来 S 组了
// 好吧，比 24T1 强 
