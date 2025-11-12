#include <bits/stdc++.h>
using namespace std;
long long ans=1,n,m,mod=998244353;
string s;
int main(){
	freopen ("employ.in","r",stdin);
	freopen ("employ.out","w",stdout);
	scanf ("%lld%lld",&n,&m);
	cin>>s;
	for (long long i=1;i<=n;i++){
		ans=((ans%mod)*i)%mod;
	}
	printf ("%lld",ans);
	return 0;
}
