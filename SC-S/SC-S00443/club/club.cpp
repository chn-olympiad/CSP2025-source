#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct Student{
	pair <int, int> fit[3];
}s[maxn];
bool cmpf(Student A, Student B) {
	return A.fit[0].first - A.fit[1].first > B.fit[0].first - B.fit[1].first;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T; scanf("%d", &T);
	while (T--) {
		int n, ans = 0, siz[3] = {0, 0, 0};
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) for (int j = 0; j < 3; j++)
			scanf("%d", &s[i].fit[j].first), s[i].fit[j].second = j;
		for (int i = 1; i <= n; i++) {
			if (s[i].fit[0].first < s[i].fit[1].first) swap(s[i].fit[0], s[i].fit[1]);
			if (s[i].fit[0].first < s[i].fit[2].first) swap(s[i].fit[0], s[i].fit[2]);
			if (s[i].fit[1].first < s[i].fit[2].first) swap(s[i].fit[1], s[i].fit[2]);
		}
		sort(s + 1, s + 1 + n, cmpf);
		for (int i = 1; i <= n; i++)
			if (siz[s[i].fit[0].second] < n / 2) 
				ans += s[i].fit[0].first, siz[s[i].fit[0].second] ++;
			else ans += s[i].fit[1].first, siz[s[i].fit[1].second]++;
		printf("%d\n", ans);		
	}
	return 0;
}