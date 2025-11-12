#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans;
int n,a[5010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	ans=0;
	for(int i=4;i<=n;i++){
		ll cnt=1,cn=1;
	    for(int j=0;j<i;j++){
	    	cnt*=(n-j);
	    	cnt%=998244353;
	    	cn*=(j+1);
	    	cn%=998244353;
		}
		cnt/=cn;
	    ans+=(cnt%998244353);
	    ans%=998244353;
	}
	ans%=998244353;
	printf("%lld",ans);
	return 0;
}
