#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 7;
int T, n, a[3][N], cnt[3], id[N];

void S(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[0][i] >> a[1][i] >> a[2][i];
	}
	cnt[0] = cnt[1] = cnt[2] = 0;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		int mx = max({a[0][i], a[1][i], a[2][i]});
		ans += mx;
		if(a[0][i] == mx) ++cnt[0], id[i] = 0;
		else if(a[1][i] == mx) ++cnt[1], id[i] = 1;
		else ++cnt[2], id[i] = 2;
	}
	if(cnt[0] > n / 2){
		vector<int> v;
		for(int i = 1; i <= n; i++){
			if(id[i] == 0) v.push_back(max(a[1][i], a[2][i]) - a[0][i]);
		}
		sort(v.begin(), v.end());
		while(v.size() > n / 2) ans += v.back(), v.pop_back();
	}else if(cnt[1] > n / 2){
		vector<int> v;
		for(int i = 1; i <= n; i++){
			if(id[i] == 1) v.push_back(max(a[0][i], a[2][i]) - a[1][i]);
		}
		sort(v.begin(), v.end());
		while(v.size() > n / 2) ans += v.back(), v.pop_back();
	}else if(cnt[2] > n / 2){
		vector<int> v;
		for(int i = 1; i <= n; i++){
			if(id[i] == 2) v.push_back(max(a[0][i], a[1][i]) - a[2][i]);
		}
		sort(v.begin(), v.end());
		while(v.size() > n / 2) ans += v.back(), v.pop_back();
	}
	cout << ans << '\n';
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--) S();
	return 0;
}
