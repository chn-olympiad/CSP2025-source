#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], ans, cnt, v[N], z, f;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);	
		if(m && a[i]) ans++;
		if(!a[i] && !m) f = 1, ans++;
	}
	if(!m && !f) printf("0");
	else printf("%d", ans);
	return 0;
}
