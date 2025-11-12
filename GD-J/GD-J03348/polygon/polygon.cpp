#include<bits/stdc++.h>
using namespace std;
int n, a[5005];long long ans;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	printf("%d", ans);
	return 0;
}

