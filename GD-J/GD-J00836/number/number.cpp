#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1 << 30;

const int N = 1e6 + 3;

int cnt[10];
char s[N];

int main () {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf ("%s", s + 1);
	int n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
		if (s[i] >= '0' && s[i] <= '9') ++cnt[s[i] - '0'];
	for (int i = 9; i >= 0; i--) for (; cnt[i]--; ) printf("%d", i);
	printf("\n");
}
