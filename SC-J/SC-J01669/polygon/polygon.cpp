#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e3 + 10,P = 998244353;

int n,ans,a[N],f[N];

int qpow(int a,int b){
	int res = 1;
	while(b > 0){
		if(b & 1) res = res * a % P;
		a = a * a % P;
		b >>= 1;
	}
	return res;
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i = 1;i <= n;i++)
		scanf("%lld",&a[i]);
	sort(a + 1,a + 1 + n);
	f[0] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= a[i];j++)
			(ans -= f[j]) %= P;
		ans = (ans % P + P) % P;
		(ans += qpow(2,i - 1)) %= P;
		for(int j = a[n];j >= a[i];j--)
			(f[j] += f[j - a[i]]) %= P;
	}
	printf("%lld\n",ans);
	return 0;
}