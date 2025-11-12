#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int MAXN = 1e6 + 10;
char s[MAXN];
int res[MAXN];
int len;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s);
	int n = strlen(s);
	for(int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9') res[len++] = (int)(s[i] - '0');
	}
	sort(res, res + len, greater<int>());
	for(int i = 0; i < len; i++) printf("%d", res[i]);
	return 0;
}
