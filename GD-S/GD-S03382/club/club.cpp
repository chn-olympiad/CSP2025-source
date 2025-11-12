#include <bits/stdc++.h>
using namespace std;
int T, n;
struct QwQ {
	int x[3], a, b, c;
} a[100005];
array<int, 3> p;
int ans;
typedef priority_queue<int, vector<int>, greater<int>> pqq;
pqq pq1, pq2;
pqq& select(int x) {
	if(x == 1)
		return pq1;
	return pq2;
}
void insert(int x) {
	pqq& qw = select(a[x].a);
	if (p[a[x].a] == n / 2) {
		int die = qw.top();
		if(a[x].x[a[x].a] - a[x].x[a[x].b] > die) {
			qw.pop();
			ans -= die;
			ans += a[x].x[a[x].a];
			qw.push(a[x].x[a[x].a] - a[x].x[a[x].b]);
		} else {
			pqq& we = select(a[x].b);
			if (p[a[x].b] == n / 2) {
				int dir = we.top();
				if(a[x].x[a[x].b] - a[x].x[a[x].c] > die) {
					we.pop();
					ans -= dir;
					ans += a[x].x[a[x].b];
					we.push(a[x].x[a[x].b] - a[x].x[a[x].c]);
				} else
					ans += a[x].x[a[x].c];
			} else {
				p[a[x].b]++;
				ans += a[x].x[a[x].b];
				we.push(a[x].x[a[x].b] - a[x].x[a[x].c]);
			}
		}
	} else {
		p[a[x].a]++;
		ans += a[x].x[a[x].a];
		qw.push(a[x].x[a[x].a] - a[x].x[a[x].b]);
	}
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 3; j++)
				cin >> a[i].x[j];
			array<pair<int,int>, 3> arr;
			arr[0] = make_pair(a[i].x[0], 0);
			arr[1] = make_pair(a[i].x[1], 1);
			arr[2] = make_pair(a[i].x[2], 2);
			sort(arr.begin(), arr.end());
			a[i].a = arr[2].second;
			a[i].b = arr[1].second;
			a[i].c = arr[0].second;
		}
		while(!pq1.empty())
			pq1.pop();
		while(!pq2.empty())
			pq2.pop();
		ans = 0;
		p[0] = p[1] = p[2] = 0;
		for (int i = 1; i <= n; i++) {
			insert(i);
		}
		cout << ans << endl;
	}
	return 0;
}

