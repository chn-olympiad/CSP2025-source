#include <bits/stdc++.h>
using namespace std;

struct p {
	int id;
	int num;
	int club;
};

int t, ans;
bool f[100010];

bool cmp(p a, p b) {
	return a.num > b.num;
}

int main() {
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> t;
	while (t--) {
		memset(f, true, sizeof(f));
		int n;
		cin >> n;
		int a[n + 1][4];
		vector<p> person;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
				person.push_back({i, a[i][j], j});
			}
		}
		
		sort(person.begin(), person.end(), cmp);
		
		int limit[10];
		int d = n / 2;
		memset(limit, 0, sizeof(limit));
		for (int i = 0; i < person.size(); i++) {
			if (limit[person[i].club] >= d || !f[person[i].id])
				continue;
			ans += person[i].num;
			limit[person[i].club]++;
			f[person[i].id] = false;
		}
		cout << ans << endl;
		ans = 0;
	}
	
	return 0;
}
