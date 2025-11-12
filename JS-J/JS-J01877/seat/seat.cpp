#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, R, r, c;
int a[105];

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d %d", &n, &m); m *= n;
	for (int i = 0; i < m; i++) scanf("%d", a+i);
	R = a[0]; sort(a, a+m, greater<int>());
	for (int i = 0; i < m; i++) if (a[i] == R){R = i; break;}
	r = R % (n << 1); c = R / n;
	if (r >= n) r = (n << 1) - r - 1;
	printf("%d %d\n", c+1, r+1);
	return 0;
}
