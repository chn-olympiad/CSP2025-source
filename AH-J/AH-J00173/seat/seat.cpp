#include<bits/stdc++.h>
using namespace std;
struct AB {
	int a;
	bool b;
}a[110];
int n, m;
bool cmp(AB a, AB b) {
	return a.a > b.a;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int len = n * m;
	a[1].b = 1;
	for(int i = 1; i <= len; ++i) {
		scanf("%d", &a[i].a);
	}
	sort(a + 1, a + 1 + len, cmp);
	int ans = 0;
	for(int i = 1; i <= m; ++i) {
		if(i % 2 == 0) {
			for(int j = n; j >= 1; --j) {
				++ans;
				if (a[ans].b) {
					printf("%d %d", i, j);
					return 0;
				}
		    }
		} else {
			for(int j = 1; j <= n; ++j) {
				++ans;
				if (a[ans].b) {
					printf("%d %d", i, j);
					return 0;
				}
		    }
		}
	}
	return 0;
}
//#Shang4Shan3Ruo6Shui4
