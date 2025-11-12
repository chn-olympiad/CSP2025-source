#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define debug(nm,val) cout<<"Debug :"<<nm<<' '<<val<<'\n'
#define mod 998244353
using namespace std;

signed main () {

	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);

	int n; scanf ("%lld",&n);
	
	vector <int> arr(n);
	int check=0;
	for (int i=0;i<n;i++) {
		
		scanf ("%lld",&arr[i]);
		check+=(arr[i]==1);
		
	}
		
	if (check==n) {
		
		int result=0,tot=n*(n-1)%mod*(n-2)%mod;
		for (int i=3;i<=n;i++) {
			result=(result+tot)%mod;
			tot=tot*(n-i)%mod;
		} printf ("%lld\n",result);
		
		return 0;
		
	} 
	
	int result=0;
	for (int i=1;i<(1<<n);i++) {
		
		int sum=0,mx=-inf,cnt=0;
		for (int j=0;j<n;j++) {
			
			if ((1<<j) & i) {
				
				sum+=arr[j];
				mx=max (mx,arr[j]);
				cnt++;
				
			}
			
		}
		
		if (sum>2ll*mx && cnt>=3) result=(result+1)%mod;
		
	} printf ("%lld\n",result);

	return 0;
}

