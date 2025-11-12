#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m, a[N], x, c;
bool cmp(int u, int v) {
	return u > v;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int cnt = n * m;
	for(int i = 1; i <= cnt; i++)
		scanf("%d", &a[i]);
	x = a[1];
	sort(a+1, a+cnt+1, cmp);
	for(int i = 1; i <= cnt; i++)
		if(a[i] == x) c = i;
	
	if(c % n == 0) {
		int u = c / n;
		if(u % 2 == 1) printf("%d %d", u, n);
		else printf("%d %d", u, 1);
	}
	else{
		int u = c / n + 1;
		if(u % 2 == 1) printf("%d %d", u, c % n);
		else printf("%d %d", u, n - c % n + 1);
	}
	return 0;
}
