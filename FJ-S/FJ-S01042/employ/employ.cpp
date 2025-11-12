#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return x * f;
}
inline void write(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9) write(x / 10);
	putchar(x % 10 ^ 48);
	return;
}
int n, m, a[100005], ans, n2 = 1;
vector<int> ak;
string s;
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) a[i] = read();
//	printf("\n");
	for (int i = 1; i <= n; i++) {
		ak.push_back(i);
		n2 *= i;
	}
	for (int k = 2; k <= n2; k++) {
		int cnt = 0, cnt2 = 0, day = 0;
		for (auto i : ak) {
			day++;
			//		cout<<i<<" "<<cnt<<" "<<a[i]<<" "<<s[day-1]<<endl;
			if (cnt >= a[i]) {
				cnt++;
				continue;
			}
			if (s[day - 1] == '0') cnt++;
			else cnt2++;
		}
//		printf("4231\n\n");
//		write(day);
//		printf(" ");
//		write(cnt);
//		printf(" ");
//		write(cnt2);
//		printf("\n");
		if (cnt2 >= m) {
		//	for (auto i : ak) {
	//			write(i);
		//		printf(" ");
		//	}
		//	printf("\n");
			ans = (ans + 1) % 998244353;
		}
		next_permutation(ak.begin(), ak.end());
	}
	write(ans);
	return 0;
}
