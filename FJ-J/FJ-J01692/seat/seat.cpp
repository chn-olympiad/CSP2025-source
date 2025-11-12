#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[101];

int main() {
	scanf("%d%d", &n, &m);
	int s = n * m;
	for (int i = 1; i <= s; i++)
		scanf("%d", &a[i]);
	int x = a[1];
	for (int i = 1; i <= s; i++)
		for (int j = i + 1; j <= s; j++)
			if (a[i] < a[j])
				swap(a[i], a[j]);
	int y;
	for (int i = 1; i <= s; i++)
		if (a[i] == x) {
			y = i;
			break;
		}
	int c = y / m;
	int r = y % m;
	if (r != 0) {
		if ((c + 1) % 2 == 0)
			r = n - r + 1;
		c++;
	}
	else
		if ((c + 1) % 2 == 0)
			r = n - r;
	printf("%d %d\n", c, r);
	return 0;
}





