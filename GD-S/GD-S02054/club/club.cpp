#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int, int>
#define debug(x) cerr << #x << ": " << x << "\n"
typedef long long ll;
using namespace std;
int n, a[100007][4], cnt[4];
struct wantt{
	int want[4], ind;
	void set(int i){
		ind = i;
		want[1] = 1, want[2] = 2, want[3] = 3;
		sort(want + 1, want + 1 + 3, [=](int t1, int t2){
			return a[i][t1] > a[i][t2];
		});
	}
	int minus(int wt){
		return abs(a[ind][want[1]] - a[ind][want[wt]]);
	}
	bool operator <(wantt b){
		return minus(2) < b.minus(2);
	}
}w[100007];
int getmx(){
	if(cnt[1] > n / 2) return 1;
	else if(cnt[2] > n / 2) return 2;
	else return 3;
}
void solve(){
	ll ans = 0;
	cin >> n;
	cnt[1] = cnt[2] = cnt[3] = 0;
 	for(int i = 1;i <= n;i++){
 		cin >> a[i][1] >> a[i][2] >> a[i][3];
 		w[i].set(i);
 		cnt[w[i].want[1]]++;
 		ans += a[i][w[i].want[1]];
	}
	sort(w + 1, w + 1 + n);
	int mx = getmx();
	for(int i = 1;i <= n;i++){
		if(cnt[mx] <= n / 2) break;
		if(w[i].want[2] != mx && w[i].want[1] == mx){
			ans -= a[w[i].ind][w[i].want[1]];
			ans += a[w[i].ind][w[i].want[2]];
			cnt[mx]--;
			cnt[w[i].want[2]]++;
		}
	}
	cout << ans << "\n";
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
}

