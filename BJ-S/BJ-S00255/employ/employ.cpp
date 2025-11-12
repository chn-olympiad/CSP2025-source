# include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int max_n = 500 + 10;
const ll mod = 998244353ll;

bool flag[max_n];
int n;
int m;
int approve, reject;
int c[max_n];
ll ans;
char s[max_n];

void DFS(int x) {
	if (x > n){
		if (approve >= m) {
			ans = (ans + 1ll) % mod;
		}
	}
	else {
		for (int i = 1; i <= n; i ++) {
			if (!flag[i]) {
				flag[i] = 1;
				if (reject >= c[i]) {
					reject ++;
					DFS(x + 1);
					reject --;
				}
				else {
					if (s[x] == '0') {
						reject ++;
						DFS(x + 1);
						reject --;
					}
					else {
						approve ++;
						DFS(x + 1);
						approve --;
					}
				}
				flag[i] = 0;
			}
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d", &n);
	scanf("%d", &m);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &c[i]);
	}
	DFS(1);
	printf("%lld", ans);
	return 0;
}