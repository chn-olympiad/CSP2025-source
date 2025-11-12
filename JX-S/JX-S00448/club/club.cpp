#include <bits/stdc++.h>
#define int long long
#define PII pair <int, int>
#define N 500005
const int INF = 1e18;
using namespace std;

int n, a[N][10], c[N];
int cnt[10];
void solve(){
	cin >> n;
	
	for(int i = 1; i <= n; i++)
		a[i][0] = a[i][1] = a[i][2] = a[i][3] = 0;
	for(int i = 1; i <= 3; i++)
		cnt[i] = 0;
		
	for(int i = 1; i <= n; i++)
		cin >> a[i][1] >> a[i][2] >> a[i][3];
	int ans = 0;
	for(int i = 1; i <= n; i++){
		int m = max({a[i][1], a[i][2], a[i][3]});
		ans += m;
		if(a[i][1] == m) cnt[1]++, c[i] = 1;
		else if(a[i][2] == m) cnt[2]++, c[i] = 2;
		else cnt[3]++, c[i] = 3;
	}
	
//	cout << ans << '\n';
//	cout << cnt[1] << ' ' << cnt[2] << ' ' << cnt[3] << '\n';
	
	if(cnt[1] <= n / 2 && cnt[2] <= n / 2 && cnt[3] <= n / 2)
		cout << ans << '\n';
	else {
		int ex = 0;
		for(int i = 1; i <= 3; i++)
			if(cnt[i] > n / 2)
				ex = i;
		priority_queue < int, vector<int>, greater<int> > q;
		for(int i = 1; i <= n; i++){
			if(c[i] == ex){
				int m = -INF;
				for(int j = 1; j <= 3; j++)
					if(j != c[i]) m = max(m, a[i][j]);
				q.push(a[i][c[i]] - m);
			}
		}
		while(cnt[ex] > n / 2)
			ans -= q.top(), q.pop(), cnt[ex]--;
		cout << ans << '\n';
	}
	
}

signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> T;
	while(T--)
		solve();
	return 0;
}
