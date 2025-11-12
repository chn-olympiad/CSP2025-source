#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct man{ //we miss you
	int idx, a[4], fav, sec_fav, del;
} a[100100];
int cnt[5];
void get_fav(man &m) {
	vector<int> temp;
	for (int i = 1; i <= 3; i++) {
		temp.push_back(m.a[i]);
	}
	sort(temp.begin(), temp.end(), greater<int>());
	for (int i = 1; i <= 3; i++) {
		if (m.a[i] == temp[0]) m.fav = i;
	}
	for (int i = 1; i <= 3; i++) {
		if (i != m.fav && m.a[i] == temp[1]) m.sec_fav = i;
	}
}
bool operator <(man a, man b) {
	return a.del < b.del;
}
void solve() {
	memset(cnt, 0, sizeof(cnt));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].a[1] >> a[i].a[2] >> a[i].a[3];
		get_fav(a[i]);
		a[i].del = a[i].a[a[i].fav] - a[i].a[a[i].sec_fav];
		cnt[a[i].fav]++;
	}
	int ans = 0;
	vector<man> joker; // 可能去自己不喜欢部门的纯 joker
	for (int i = 1; i <= n; i++) {
		ans += a[i].a[a[i].fav];
		if (cnt[a[i].fav] > n / 2) {
			joker.push_back(a[i]);
		}
	}
	sort(joker.begin(), joker.end());
	for (int i = 0; i < (int)joker.size() - n / 2; i++) {
		ans -= joker[i].del;
	}
	cout << ans << '\n';
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}

/*
15:04 Pretests Passed(5)

my luogu UID is 928955
follow me if you see this code
*/