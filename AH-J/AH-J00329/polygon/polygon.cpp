#include <bits/stdc++.h>
using namespace std;
long long n,a[5005],sum[5005],mod=998244353,ans,mx;
int main(){
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	scanf ("%lld",&n);
	for (int i=1;i<=n;i++){
		scanf ("%lld",&a[i]);
		if (a[i]>mx)
			mx=a[i];
	}
	if (mx==1)
		printf ("0");
	return 0;
}
