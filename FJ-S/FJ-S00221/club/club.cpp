#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5 + 5;

int T, n, cnt[4], tmp[5];
ll ans;

inline int Read() {
	int sum = 0, fl = 1;
	int ch = getchar();
	for (; !isdigit(ch); ch = getchar())
	if (ch == '-') fl = -1;
	for (; isdigit(ch); ch = getchar()) sum = sum * 10 + ch - '0';
	return sum * fl;
}

struct Member {
	int a, b, c, val1, val2, num, id;
} s[N];

bool cmp(Member x, Member y) {
	if (x.num == y.num) {
		return x.val1 > y.val1;
	} return x.num > y.num;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	T = Read();
	while (T--) {
		n = Read();
		cnt[1] = cnt[2] = cnt[3] = 0;
		tmp[1] = tmp[2] = tmp[3] = tmp[4] = 0;
		for (int i = 1; i <= n; i++) {
			s[i].a = Read();
			s[i].b = Read();
			s[i].c = Read();
			s[i].val1 = max(s[i].a, max(s[i].b, s[i].c));
			s[i].val2 = min(s[i].a, min(s[i].b, s[i].c));
			s[i].num = s[i].val1 - s[i].val2;
			if (s[i].a >= s[i].b && s[i].a >= s[i].c) s[i].id = 1;
			else if (s[i].b >= s[i].a && s[i].b >= s[i].c) s[i].id = 2;
			else s[i].id = 3;
		}
		sort(s + 1, s + 1 + n, cmp);
		ans = 0;
		for (int i = 1; i <= n; i++) {
			if (cnt[s[i].id] * 2 < n) {
				if (s[i].id == 1) {
					if (s[i].a == s[i].b) tmp[2]++;
					if (s[i].a == s[i].c) tmp[3]++;
					if (s[i].a == s[i].b && s[i].a == s[i].c) tmp[4]++;
				} else if (s[i].id == 2) {
					if (s[i].b == s[i].a) tmp[1]++;
					if (s[i].b == s[i].c) tmp[3]++;
					if (s[i].a == s[i].b && s[i].a == s[i].c) tmp[4]++;
				} else {
					if (s[i].c == s[i].a) tmp[1]++;
					if (s[i].c == s[i].b) tmp[2]++;
					if (s[i].a == s[i].b && s[i].a == s[i].c) tmp[4]++;
				}
				ans += s[i].val1;
				cnt[s[i].id]++;
			} else {
				if (s[i].id == 1) {
					int flag = 0;
					if (tmp[2] > tmp[3] && tmp[2]) cnt[2]++, ans += s[i].val1, flag = 1;
					if (tmp[3] > tmp[2] && tmp[3]) cnt[3]++, ans += s[i].val1, flag = 2;
					if (flag) {
						if (flag == 1 && tmp[2] < tmp[4]) tmp[3]--, tmp[4]--;
						if (flag == 2 && tmp[3] < tmp[4]) tmp[2]--, tmp[4]--;
						continue;
					}
				} else if (s[i].id == 2) {
					int flag = 0;
					if (tmp[1] > tmp[3] && tmp[1]) cnt[1]++, ans += s[i].val1, flag = 1;
					if (tmp[3] > tmp[1] && tmp[3]) cnt[3]++, ans += s[i].val1, flag = 2;
					if (flag) {
						if (flag == 1 && tmp[1] < tmp[4]) tmp[3]--, tmp[4]--;
						if (flag == 2 && tmp[3] < tmp[4]) tmp[1]--, tmp[4]--;
						continue;
					}
				} else {
					int flag = 0;
					if (tmp[2] > tmp[1] && tmp[2]) cnt[2]++, ans += s[i].val1, flag = 1;
					if (tmp[1] > tmp[2] && tmp[1]) cnt[1]++, ans += s[i].val1, flag = 2;
					if (flag) {
						if (flag == 1 && tmp[2] < tmp[4]) tmp[1]--, tmp[4]--;
						if (flag == 2 && tmp[1] < tmp[4]) tmp[2]--, tmp[4]--;
						continue;
					}
				}
				if (s[i].id == 1) ans += max(s[i].b, s[i].c);
				else if (s[i].id == 2) ans += max(s[i].a, s[i].c);
				else ans += max(s[i].a, s[i].b);
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}

//17:28,重拾，我就不信了，一个小时想不出来？ 
//17:50,用差值排序，发现过了第五个样例。。不是？谁家好人大样例这么水，那只有ccf（大概是哪里写错了？
//18:26,退役快乐！ 
