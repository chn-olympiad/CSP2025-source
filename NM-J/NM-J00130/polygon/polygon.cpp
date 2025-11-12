#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int n;
int a[5003];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	if(a[1] + a[2] + a[3] > 2 *a[3]) printf("1");
	else printf("0");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
