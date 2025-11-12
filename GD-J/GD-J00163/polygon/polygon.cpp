#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 4e6 + 10, mod = 998244353;

int n,a[N],sum[N],f[N],ans;
#define lb(x) (x&(-x))
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=x*x%mod) if (y&1) res*=x;
	return res;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if (n<=20){
		for (int i=1;i<=n;i++) cin >> a[i],sum[1<<i-1]=f[1<<i-1]=a[i];
		for (int i=1;i<=(1<<n)-1;i++){
			sum[i]=sum[i^lb(i)]+sum[lb(i)],f[i]=max(f[i^lb(i)],f[lb(i)]);
			if (sum[i]>2*f[i]) ans++;
		}	 
	}
	else{
		ans=(qpow(2,n)-1-n-n*(n-1)/2+mod)%mod;
	}
	cout << ans;
}
/*
21
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/
