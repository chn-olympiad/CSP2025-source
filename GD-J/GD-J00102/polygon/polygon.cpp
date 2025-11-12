#include<bits/stdc++.h>
using namespace std;
const int N=100001,M=5000;
long long mod=998244353,n,a[N],f[N],ans,ma;
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	f[0]=1;
	sort(a+1,a+1+n);
	for(int i=1; i<=n; i++) {
		for(int j=a[i]+1; j<=a[n]; j++)
			ans+=f[j];
		ans+=ma;
		ans%=mod;
		ma*=2;
		for(int j=a[n]; j>=0; j--)
			if(a[i]+j<=a[n]) {
				f[a[i]+j]+=f[j];
				f[a[i]+j]%=mod;
			} else 
				ma+=f[j];
		ma%=mod;
	}
	cout<<ans<<"\n";
	return 0; 
}//366911923
/*5
1 1 2 2 3 */
