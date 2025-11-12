#include<bits/stdc++.h>
using namespace std;
int n, m;
const long long P = 998244353;
bool S[502];
bool F = true;
void in() {
	char s[502];
	scanf("%s", s + 1);
	memset(S, 0, sizeof(S);
	for (int i = 1; i <= n; i++) {
		S[i] = s[i] == '1';
		if (s[i] == '0') {
			F = false;
		}
	}
	return;
}
int c[501];
void f() {
	long long sum = 1;
	for (int i = n; i > 0; i--) {
		sum *= i % P;
		sum %= P;
	}
	printf("%lld\n", sum);
}
int main() {
	freopen("employ.in", "r", std::in);
	freopen("employ.out", "w", std::out);
	scanf("%d%d", &n, &m);
	in();
	if (F) {
		f();
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}
	return 0;
}
