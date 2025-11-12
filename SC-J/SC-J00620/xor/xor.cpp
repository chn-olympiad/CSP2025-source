#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10, maxm = 1e3 + 10, maxk = 300;

int a[maxn], s[maxn];
int f[maxn];
int g[maxn];
bool flagB = 1, flagC = 1;

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;scanf("%d%d", &n, &k);
	for (int i = 1;i <= n;i ++) scanf("%d", &a[i]);
	for (int i = 1;i <= n;i ++) s[i] = s[i - 1] ^ a[i];
	for (int i = 1;i <= n;i ++) {
		if (a[i] > 1) flagB = 0;
		if (a[i] > 255) flagC = 0;
	}
	if (n <= 20010) {//expect 60pts or cheat more
		for (int i = 1;i <= n;i ++) {
			for (int j = 1;j <= i;j ++) {
				if ((s[i] ^ s[j - 1]) == k) {
					f[i] = max(f[i], f[j - 1] + 1);
				} else {
					f[i] = max(f[i], f[j - 1]);
				}
			}
		}
		printf("%d", f[n]);
	} 
	return 0;
}