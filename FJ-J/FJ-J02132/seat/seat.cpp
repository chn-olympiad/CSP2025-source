#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int a[N * N];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int len = n * m;
    for (int i = 1;i <= len;i++) {
    	cin >> a[i];
	}
	int temp = a[1];
	sort(a + 1, a + len + 1, cmp);
	int i = 1, j = 1, tot = 1;
	int dir = 1;
	while (a[tot] != temp) {
		if (i > n || i < 1) {
			i -= dir;
			j++;
			dir = -dir;
		}
		i += dir;
		tot++;
	}
	if (i > n || i < 1) {
		i -= dir;
		j++;
		dir = -dir;
	}
	cout << j << ' ' << i;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
