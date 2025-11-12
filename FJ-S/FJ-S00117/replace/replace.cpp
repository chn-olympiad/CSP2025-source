#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5, L = 5e6 + 5;
int n, q;
string c;

struct Node {
	int a, b, c, d;
} s[N], t;

int get() {
	for (int i = 0; i < c.size(); i++)
		if (c[i] == 'b')
			return i;
	return 0;
}

void __solve1() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> c;
		int pos = get();
		s[i].a = pos, s[i].b = c.size() - pos - 1;
		cin >> c;
		pos = get();
		s[i].c = pos, s[i].d = c.size() - pos - 1;
	}
	while (q--) {
		cin >> c;
		int pos = get();
		t.a = pos, t.b = c.size() - pos - 1;
		cin >> c;
		pos = get();
		t.c = pos, t.d = c.size() - pos - 1;
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (t.a - s[i].a + s[i].c == t.c && t.b - s[i].b + s[i].d == t.d)
				ans++;
		printf("%d\n", ans);
	}
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	__solve1();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
