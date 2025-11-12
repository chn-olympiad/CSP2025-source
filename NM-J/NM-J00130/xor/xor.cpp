#include<bits/stdc++.h>
using namespace std;

int n, k;
int a[500005];
int c[500005];

int main() {
	freopen("xor5.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	memset(c, 127, sizeof(c));
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int snt = 0, l = 0;
		for(int j = i; j <= n; j++) {
			snt ^= a[j], l++;
			if(snt == k) snt = 0, c[j - l + 1] = min(c[j - l + 1], j), l = 0;
		}
	}
	for(int i = 1; i <= n; i++)
		if(c[i] != c[0]) ans++, i = c[i];
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
