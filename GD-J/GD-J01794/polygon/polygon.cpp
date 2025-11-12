#include <bits/stdc++.h>
using namespace std;
const int N = 5005, mo = 998244353;
int n, m, i, j, k, ans, a[N], f[N<<1];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(i=1; i<=n; i++) scanf("%d", a+i);
	sort(a+1, a+n+1);
	for(f[0]=i=1; i<=n; i++){
		for(k=0, j=a[i]+1; j<N; j++) k = (k+f[j])%mo;
		ans = (ans+k)%mo;
		for(k=0, j=2*N-1; j>=a[i]; j--){
			f[j] = (f[j]+f[j-a[i]])%mo;
			if(j >= N) k = (k+f[j])%mo, f[j] = 0;
		}
		f[N-1] = (f[N-1]+k)%mo;
	}
	printf("%d\n", ans);
	return 0;
}
