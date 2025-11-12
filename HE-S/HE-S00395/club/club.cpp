#include <iostream>
#include <algorithm>
using namespace std;

long long t, n, maxx, ans, prev;
struct Student { 
	pair<long long, long long> a[4];
	bool flag[4] = { true, true, true, true }, shit = false;
	
}stu[100005];
struct Club { long long cnt = 0; } club[4];

bool cmp(const Student& a, const Student& b) {
	if (a.a[1].first == b.a[1].first) {
		if (a.a[2].first == b.a[2].first) return a.a[3].first < b.a[3].first;
		return a.a[2].first < b.a[2].first;
	}
	else return a.a[1].first > b.a[1].first;
}

bool check(int i, int num) {
	if (stu[i + 1].shit) return true;
	int cnt = 0;
	for (int j = 1;j <= 3;j++) {
		if (j == num) continue;
		if (!stu[i + 1].flag[j]) cnt++;
	}
	if (cnt == 2) {
		if (!club[stu[i].a[num].second].cnt) return club[stu[i].a[num].second].cnt + 2 <= maxx;
		return club[stu[i].a[num].second].cnt + 1 <= maxx;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		ans = 0;
		cin >> n;
		maxx = n / 2;
		for (int i = 1;i <= n;i++) {
			cin >> stu[i].a[1].first >> stu[i].a[2].first >> stu[i].a[3].first;
			stu[i].a[1].second = 1, stu[i].a[2].second = 2, stu[i].a[3].second = 3;
			if (!stu[i].a[1].first) stu[i].flag[1] = false;
			if (!stu[i].a[2].first) stu[i].flag[2] = false;
			if (!stu[i].a[3].first) stu[i].flag[3] = false;
			if (stu[i].flag[1] && stu[i].flag[2] && stu[i].flag[3]) stu[i].shit = true;
			sort(stu[i].a + 1, stu[i].a + 1 + 3, greater<pair<int, int>>());
		}
		sort(stu + 1, stu + 1 + n, cmp);
		for (int i = 1;i <= n;i++) {
			if (club[stu[i].a[1].second].cnt < maxx && check(i, stu[i].a[1].second)) {
				ans += stu[i].a[1].first;
				club[stu[i].a[1].second].cnt++;
			}
			else if (club[stu[i].a[2].second].cnt < maxx && check(i, stu[i].a[2].second)) {
				ans += stu[i].a[2].first;
				club[stu[i].a[2].second].cnt++;
			}
			else if (club[stu[i].a[3].second].cnt < maxx && check(i, stu[i].a[3].second)) {
				ans += stu[i].a[3].first;
				club[stu[i].a[3].second].cnt++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
