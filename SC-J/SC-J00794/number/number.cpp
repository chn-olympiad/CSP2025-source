#include <bits/stdc++.h>
constexpr int N = 1e6 + 10;

int n;
char v[N], s[N];

void extract() {
	for (const auto c : s) {
		if (isdigit(c)) v[n++] = c;
		else if (!isalpha(c)) break;
	}
}

auto main() -> int {
	freopen("number.in", "r", stdin), freopen("number.out", "w", stdout);
	fgets(s, N, stdin), extract();
	std::sort(v, v + n, std::greater<int>{});
	puts(v);
}
