#include <iostream>

const int MAXN = 5e5 + 5;
int wf[MAXN], f[MAXN];

int w(int l, int r) {
	return wf[r] ^ wf[l - 1];
}

int main(void) {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int n, k;
	std::cin >> n >> k;
	for (int i = 1, a; i <= n; ++i) {
		std::cin >> a;
		wf[i] = wf[i - 1] ^ a;
	}
	
	for (int i = 1; i <= n; ++i) {
		f[i] = f[i - 1];
		for (int j = 1; j <= i; ++j) {
			if (w(j, i) == k) {
				f[i] = std::max(f[i], f[j - 1] + 1);
			}
		}
	}
	std::cout << f[n] << '\n';
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
