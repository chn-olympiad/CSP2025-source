#include<bits/stdc++.h>
#define ll long long
#define str string
#define db double
using namespace std;
constexpr ll MAXN = 1e5 + 5;
ll t, n, ans = 0;
class person {
public:
	ll a, b, c;
} stu[MAXN];
vector<person> clb1, clb2, clb3;
inline bool cmp1(person x, person y) {
	return x.a - max(x.b, x.c) > y.a - max(y.b, y.c);
}
inline bool cmp2(person x, person y) {
	return x.b - max(x.a, x.c) > y.b - max(y.a, y.c);
}
inline bool cmp3(person x, person y) {
	return x.c - max(x.a, x.b) > y.c - max(y.a, y.b);
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> t;
	while (t--) {
		cin >> n, ans = 0, clb1.clear(), clb2.clear(), clb3.clear();
		for (ll i = 1; i <= n; ++i) {
			cin >> stu[i].a >> stu[i].b >> stu[i].c;
			if (stu[i].a == max({stu[i].a, stu[i].b, stu[i].c}))
				clb1.emplace_back(stu[i]);
			else if (stu[i].b == max({stu[i].a, stu[i].b, stu[i].c}))
				clb2.emplace_back(stu[i]);
			else clb3.emplace_back(stu[i]);
		}
		if (clb1.size() > n / 2) {
			sort(clb1.begin(), clb1.end(), cmp1);
			while (clb1.size() > n / 2) {
				person t = clb1.back();
				clb1.pop_back();
				if (t.b > t.c) clb2.emplace_back(t);
				else clb3.emplace_back(t);
			}
		} else if (clb2.size() > n / 2) {
			sort(clb2.begin(), clb2.end(), cmp2);
			while (clb2.size() > n / 2) {
				person t = clb2.back();
				clb2.pop_back();
				if (t.a > t.c) clb1.emplace_back(t);
				else clb3.emplace_back(t);
			}
		} else if (clb3.size() > n / 2) {
			sort(clb3.begin(), clb3.end(), cmp3);
			while (clb3.size() > n / 2) {
				person t = clb3.back();
				clb3.pop_back();
				if (t.a > t.b) clb1.emplace_back(t);
				else clb2.emplace_back(t);
			}
		}
		for (const person & v : clb1) ans += v.a;
		for (const person & v : clb2) ans += v.b;
		for (const person & v : clb3) ans += v.c;
		cout << ans << '\n';
	}
	return 0;
}