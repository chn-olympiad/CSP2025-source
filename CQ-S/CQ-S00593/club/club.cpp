//luogu uid 755230 jzc114514
//100!
#include<bits/stdc++.h>
#define ll long long
#define int ll
#define fs first
#define se second
#define pii pair<int, int>
#define db double
#define lp (p * 2)
#define rp (p * 2 + 1)
#define all(s) s.begin(), s.end()
using namespace std;
inline void cmax(int &a, int b){if(a < b)a = b;}
inline void cmin(int &a, int b){if(a > b)a = b;}
bool cmp(pii a, pii b){
	return a > b;
}
void solve(){
	const int N = 1e5 + 5;
	int n;
	pii s[N][4] = {}, a[N] = {};
	cin >> n;
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= 3; j ++){
			cin >> s[i][j].fs;
			s[i][j].se = j;
		}
		sort(s[i] + 1, s[i] + 4, cmp);
		a[i] = {s[i][1].fs - max(s[i][2].fs, s[i][3].fs), 
			s[i][1].se};
	}
	priority_queue<pii, vector<pii>, greater<pii> > q[4];
	int ans = 0;
	for(int i = 1; i <= n; i ++){
		int fav = a[i].se;
		q[fav].push(a[i]);
		ans += s[i][1].fs;
		if((int)q[fav].size() > n / 2){
			auto tmp = q[fav].top();
			q[fav].pop();
			ans -= tmp.fs;
		}
	}
	cout << ans << "\n";
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
	cin >> T;
	while(T --){
		solve();
	}
}

