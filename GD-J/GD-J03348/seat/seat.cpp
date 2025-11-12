#include<bits/stdc++.h>
using namespace std;
int n, m, a[110], r_grade;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int g = n * m;
	for(int i = 1; i <= g; i++) scanf("%d", a + i);
	r_grade = a[1];
	sort(a + 1, a + g + 1, greater<int>());
	for(int i = 1; i <= g; i++) if(a[i] == r_grade) {
		int c = (i - 1) / n + 1, r;
		int x = (i - 1) % n;
		if(c % 2) r = x + 1;
		else r = n - x;
		printf("%d %d", c, r);
	}
}

