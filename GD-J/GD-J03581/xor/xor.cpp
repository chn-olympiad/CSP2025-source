#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,k;
ll a[500005],s[500005],f[500005];

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for (int i = 1; i <= n; i++) scanf("%lld",&a[i]),s[i] = s[i - 1] ^ a[i];
	if (n <= 2e5) {
		for (int i = 1; i <= n; i++) {
			f[i] = f[i - 1];
			for (int j = i; j >= max(i - 3000,1); j--)
				if ((s[i] ^ s[j - 1]) == k)
					f[i] = max(f[i],f[j - 1] + 1);
		}
	} else {
		for (int i = 1; i <= n; i++) {
			f[i] = f[i - 1];
			for (int j = i; j >= max(i - 1000,1); j--)
				if ((s[i] ^ s[j - 1]) == k)
					f[i] = max(f[i],f[j - 1] + 1);
		}
	}
	printf("%lld\n",f[n]);
	return 0;
}
