#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

const int MAXN = 100005;
int t, n, a[MAXN], b[MAXN], c[MAXN];
long long cnt = 0;
bool is_A = true, is_B = true;
char big_flag = 'a';
vector<int> a_member, b_member, c_member;

bool cmp_greater(int lhs, int rhs) {
	return lhs > rhs;
}

bool cmp_minus_less(int lhs, int rhs) {
	return abs(a[lhs] - b[lhs]) < abs(a[lhs] - b[lhs]);
}

bool cmp_minus_3(int lhs, int rhs) {
	if (big_flag == 'a')
		return min(a[lhs] - b[lhs], a[lhs] - c[lhs]) < min(a[rhs] - b[rhs], a[rhs] - c[rhs]);
	if (big_flag == 'b')
		return min(b[lhs] - a[lhs], b[lhs] - c[lhs]) < min(b[rhs] - a[rhs], b[rhs] - c[rhs]);
	return min(c[lhs] - a[lhs], c[lhs] - b[lhs]) < min(c[rhs] - a[rhs], c[rhs] - b[rhs]);
}

bool is_member_okay() {
	if (big_flag == 'a')return b_member.size() <= n/2 && c_member.size() <= n/2;
	if (big_flag == 'b')return a_member.size() <= n/2 && c_member.size() <= n/2;
	return a_member.size() <= n/2 && b_member.size() <= n/2;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		// init
		cnt = 0;
		is_A = true;
		is_B = true;
		a_member.clear();
		b_member.clear();
		c_member.clear();
		for (int i = 1; i <= n; ++i) {
			cin >> a[i] >> b[i] >> c[i];
			if (b[i] != 0 || c[i] != 0)is_A = false;
			if (c[i] != 0)is_B = false;
		} 
		if (is_A) {
			sort(a + 1, a + n + 1, cmp_greater);
			for (int i = 1; i <= n/2; ++i) {
				cnt += a[i];
			}
			cout << cnt << endl;
			continue;
		}
		// else
		for (int i = 1; i <= n; ++i) {
			if (a[i] >= b[i] && a[i] >= c[i]) {
				a_member.push_back(i);
				cnt += a[i];
			} else if (b[i] >= a[i] && b[i] >= c[i]) {
				b_member.push_back(i);
				cnt += b[i];
			} else {
				c_member.push_back(i);
				cnt += c[i];
			}
		}
		vector<int> &big_depart = a_member;
		big_flag = 'a';
		if (b_member.size() > n/2) {
			big_depart = b_member;
			big_flag = 'b';
		}
		else if (c_member.size() > n/2) {
			big_depart = c_member;
			big_flag = 'c';
		}
		else if (a_member.size() <= n/2) {
			// All department is OK
			cout << cnt << endl;
			continue;
		}
		sort(big_depart.begin(), big_depart.end(), cmp_minus_3);
		for (int i = 0; i < big_depart.size() - n/2; ++i) {
			int id = big_depart[i];
			if (big_flag == 'a') {
				cnt -= min(a[id] - b[id], a[id] - c[id]);
			} else if (big_flag == 'b') {
				cnt -= min(b[id] - a[id], b[id] - c[id]);
			} else if (big_flag == 'c') {
				cnt -= min(c[id] - b[id], c[id] - a[id]);
			}
		}
		cout << cnt << endl;
		continue;
	}
	return 0;
}
