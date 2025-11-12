#include <bits/stdc++.h>
using namespace std;
struct student {
	long long u, v, w;
};
int n;
bool cmp1(student a, student b) {
	return a.u <= b.u;
}
bool cmp2(student a, student b) {
	return a.v <= b.v;
}
bool cmp3(student a, student b) {
	return a.w <= b.w;
}
bool go(vector<student> s, int op) {
	if (op == 1) {
		sort(s.begin(), s.end(), cmp1);
	}
	if (op == 2) {
		sort(s.begin(), s.end(), cmp2);
	}
	if (op == 3) {
		sort(s.begin(), s.end(), cmp3);
	}
}
long long mysort(vector<student> st, int a, int b, int c) {
	int ans = 0;
	go(st, a);
	for (int i = 1; i <= n / 2; i++) {
		student fz = st.back();
		ans += (a == 1 ? fz.u : (a == 2 ? fz.v : fz.w));
		st.pop_back();
	}
	go(st, b);
	for (int i = 1; i <= n / 2; i++) {
		student fz = st.back();
		ans += (b == 1 ? fz.u : (b == 2 ? fz.v : fz.w));
		st.pop_back();
	}
	go(st, c);
	for (int i = 1; i <= n / 2; i++) {
		student fz = st.back();
		ans += (c == 1 ? fz.u : (c == 2 ? fz.v : fz.w));
		st.pop_back();
	}
	return ans;
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, u, v, w;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<student> students;
		int num = 1;
		for (int i = 1; i <= n; i++) {
			cin >> u >> v >> w;
			students.push_back((student){u, v, w});
		}
		long long ans = 0;
		ans = max(ans, mysort(students, 1, 2, 3));
		ans = max(ans, mysort(students, 1, 3, 2));
		ans = max(ans, mysort(students, 2, 1, 3));
		ans = max(ans, mysort(students, 2, 3, 1));
		ans = max(ans, mysort(students, 3, 1, 2));
		ans = max(ans, mysort(students, 3, 2, 1));
		cout << ans << endl;
	}
}

