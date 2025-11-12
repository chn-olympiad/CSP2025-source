#include<bits/stdc++.h>
#define nmf(i,s,e) for(int i=s;i<=e;i++)
#define ref(i,s,e) for(int i=s;i>=e;i--)
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
struct node {
	LL a, b, c;
} s[100005];
int n;
vector<LL> v[3];
void solve() {
	cin >> n;
	int cnt[3] = {};
	v[0].clear();
	v[1].clear();
	v[2].clear();
	LL ans = 0;
	nmf(i, 1, n) {
		cin >> s[i].a >> s[i].b >> s[i].c;
		if (s[i].a >= max(s[i].b, s[i].c))cnt[0]++, v[0].emplace_back(max(s[i].b, s[i].c) - s[i].a), ans += s[i].a;
		else if (s[i].b >= max(s[i].a, s[i].c))cnt[1]++, v[1].emplace_back(max(s[i].a, s[i].c) - s[i].b), ans += s[i].b;
		else if (s[i].c >= max(s[i].a, s[i].b))cnt[2]++, v[2].emplace_back((max(s[i].a, s[i].b) - s[i].c)), ans += s[i].c;
	}
	int x = max_element(cnt, cnt + 3) - cnt;
	if (cnt[x] > n / 2) {
		sort(v[x].begin(), v[x].end(), greater<LL>());
		int pos = 0;
		while (cnt[x] > n / 2) {
			ans += v[x][pos];
			pos++;
			cnt[x]--;
		}
	}
	cout << ans << '\n';
	return;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--)solve();
	return 0;
}