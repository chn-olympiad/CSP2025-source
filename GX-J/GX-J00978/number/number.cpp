#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;

int n;
char s[N];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	std::vector<int> a;
	for (int i = 1; i <= n; i++) if (s[i] >= '0' && s[i] <= '9')
		a.push_back(s[i] - '0');
	std::sort(a.begin(), a.end());
	int len = a.size();
	for (int i = len - 1; i >= 0; --i) {
		printf("%d", a[i]);
	}
}