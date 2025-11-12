#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10,M = 4e6 + 10;

int n,k,a[N],f[N],t[M];

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(int i = 1;i <= n;i++)
		scanf("%lld",&a[i]);
	for(int i = 2;i <= n;i++)
		a[i] ^= a[i - 1];
	for(int i = 1;i < M;i++)
		t[i] = -1;
	for(int i = 1;i <= n;i++){
		f[i] = t[a[i] ^ k] + 1;
		f[i] = max(f[i],f[i - 1]);
		t[a[i]] = max(t[a[i]],f[i]);
	}
	printf("%lld\n",f[n]);
	return 0;
}