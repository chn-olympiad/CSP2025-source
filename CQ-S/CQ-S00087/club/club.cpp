#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i, j, k) for(int i = (j); i <= (k); i ++)
#define per(i, j, k) for(int i = (j); i >= (k); i --)
#define pb emplace_back
#define fi first
#define se second
using vi = vector<int>;
using pi = pair<int, int>;

template<typename T0, typename T1> bool chmin(T0 &x, const T1 &y){
	if(y < x){x = y; return true;} return false;
}
template<typename T0, typename T1> bool chmax(T0 &x, const T1 &y){
	if(x < y){x = y; return true;} return false;
}

template<typename T> void debug(char *s, T x){
	cerr << s <<" = "<< x << endl;
}
template<typename T, typename ...Ar> void debug(char *s, T x, Ar... y){
	int dep = 0;
	while(!(dep == 0 && *s == ',')){
		if(*s == '(') dep ++;
		if(*s == ')') dep --;
		cerr << *s ++;
	}
	cerr << " = " << x << ",";
	debug(s + 1, y...);
}
#define gdb(...) debug((char*)#__VA_ARGS__, __VA_ARGS__)

void solve(){
	int n;
	cin >> n;
	vector< array<int, 3> > a(n);
	vi idx(n), cnt(3);
	int ans = 0;
	rep(i, 0, n - 1){
		rep(j, 0, 2){
			cin >> a[i][j];
		}
		int mx = max_element(a[i].begin(), a[i].end()) - a[i].begin();
		idx[i] = mx;
		ans += a[i][mx];
		cnt[mx] ++;
	}
	int mx = max_element(cnt.begin(), cnt.end()) - cnt.begin();
	int c = max(0, cnt[mx] - n / 2);
	vi ve;
	rep(i, 0, n - 1){
		if(idx[i] != mx){
			continue;
		}
		int mmx = 0;
		rep(j, 0, 2){
			if(j != mx){
				chmax(mmx, a[i][j]);
			}
		}
		ve.pb(a[i][mx] - mmx);
	}
	if(c){
		sort(ve.begin(), ve.end());
		// nth_element(ve.begin(), ve.begin() + (c - 1), ve.end());
		ans -= accumulate(ve.begin(), ve.begin() + c, 0);
	}
	cout << ans <<'\n';
}

signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t --){
		solve();
	}
}
