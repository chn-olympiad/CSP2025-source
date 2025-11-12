#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int n, k;
int a[N];
int main() {
	int i;
	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	scanf("%d%d", &n, &k);
	for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
	
	int cnum = -1, ans = 0;
	for (i = 1; i <= n; ++i) {
		if (cnum == -1) cnum = a[i];
		else cnum ^= a[i];
		
		if (a[i] == k) ++ans, cnum = -1;
		else if (cnum == k) ++ans, cnum = -1;
	}
	
	printf("%d", ans);
	
	return 0;
}

