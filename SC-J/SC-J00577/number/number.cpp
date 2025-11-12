#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, a[N];
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	for (size_t i = 0; i < s.size(); ++i)
		if (isdigit(s[i]))
			a[++n] = s[i] - '0';
	sort(a + 1, a + n + 1);
	for (int i = n; i; --i)
		printf("%d", a[i]);
	puts("");
	fclose(stdin), fclose(stdout);
	return 0;
}