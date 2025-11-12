#include <cstdio>
#include <algorithm>
const int mod = 998244353;

inline void read(int &goal) {
	int x = 0;
	char c = getchar();
	while (c > 57 || c < 48) c = getchar();
	while (c > 47 && c < 58) {
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	goal = x;
}
inline void write(int n) {
	char buffer[9], *pos = buffer;
	do *pos++ = n % 10 + 48; while (n /= 10);
	do putchar(*--pos); while (pos > buffer);
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	int n, m, cnt = 0; read(n); read(m);
	int *c = new int[n], *employ = new int[n];
	for (int i = 0; i < n; i++) employ[i] = i + 1;
	bool *dif = new bool[n];

	for (int i = 0; i < n; i++)
		dif[i] = (getchar() == '0');
		
	for (int i = 0; i < n; i++) read(c[i]);

	do {
		int curEmploy = 0;
		for (int i = 0; i < n; i++)
			if (!dif[employ[i] - 1] && c[employ[i] - 1] > curEmploy)
				curEmploy++;	
		if (curEmploy >= m) cnt = (cnt + 1) % mod;
	} while (std::next_permutation(employ, employ + n));

	write(cnt);

	delete[] c;
	delete[] employ;
	delete[] dif;
	return 0;
}
