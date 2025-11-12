#include <cstdio>
#include <algorithm>
using namespace std;

struct pir {
	int first, second;
};
struct good {
	int value[3];
	inline pir mx() const {
		int val = value[0], index = 0;
		if (value[1] > val) {
			val = value[1];
			index = 1;
		}
		if (value[2] > val) {
			val = value[2];
			index = 2;
		}
		return {val, index};
	}
	inline int maxOther(int self) {
		return max(max((self == 0 ? 0 : value[0]), (self == 1 ? 0 : value[1])),
			   (self == 2 ? 0 : value[2]));
	}
};

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
	if (n == 0) {
		putchar('0');
		return;
	}
	char buffer[10], *pos = buffer;
	do *pos++ = n % 10 + 48; while (n /= 10);
	do putchar(*--pos); while (pos > buffer);
}
int than;
bool cmp(good x, good y) {
	return x.value[than] - x.maxOther(than) < y.value[than] - y.maxOther(than);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	int t; read(t);
	while (t--) {
		int n, ans = 0; read(n);

		good *a = new good[n];
		for (int i = 0; i < n; i++) {
			read(a[i].value[0]); read(a[i].value[1]); read(a[i].value[2]);
		}

		int cho[3] = {0};
		for (int i = 0; i < n; i++) {
			pir curMax = a[i].mx();
			ans += curMax.first;
			cho[curMax.second]++;
		}
		for (int i = 0; i < 3; i++) {
			if (cho[i] <= (n >> 1)) continue;
			than = i;
			sort(a, a + n, cmp);
			for (int j = 0; j < cho[i] - (n >> 1); j++) {
				ans -= a->value[i] - a->maxOther(i);
			}
			break;
		}

		write(ans);
		putchar('\n');

		delete[] a;
	}
	return 0;
}
