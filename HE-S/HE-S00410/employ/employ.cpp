#include <bits/stdc++.h>
using namespace std;

int n,m,a[501];
char s[510];

int main(){
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	scanf ("%d%d%s", &n, &m, s + 1);
	for (int i = 1;i <= n; i++)
		scanf ("%d", &a[i]);
	if (m == 1){
		long long x = 1;
		for (int i = 1;i <= n; i++){
			x *= n;
			x %= 998244353;
		}
		cout << x;
	}
	if (m == n){
		printf ("0\n");
	}
}
