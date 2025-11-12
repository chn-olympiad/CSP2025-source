#include<iostream>
#include<algorithm>
using namespace std;
int mian(); int main() { return mian(); }

#define ll long long
const int N = 555;
int n, m, c[N], p[N], _;

char S[N];

int mian() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	_ = scanf("%d%d%s", &n, &m, S + 1);
	for(int i = 1; i <= n; ++i) _ = scanf("%d", &c[i]), p[i] = i;
	int ans = 0;
	do {
		int cnt = 0, fail = 0;
		for(int i = 1; i <= n; ++i) {
			if(fail >= c[p[i]] or S[i] == '0') {
				fail++;
			}
			else cnt++;
		}
		if(cnt >= m) ans++;
	} while(next_permutation(p + 1, p + 1 + n));
	printf("%d\n", ans);
	return 0;
}