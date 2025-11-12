#include <bits/stdc++.h>
using namespace std;
const int N = 1000050;
int n, m, i, j, k, b[N];
char c, a[N];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", a+1);
	for(i=1; c=a[i]; i++){
		if('0'<=c && c<='9') b[++n] = c-'0';
	}
	sort(b+1, b+n+1);
	for(i=n; i; i--) printf("%d", b[i]);
	return 0;
}
