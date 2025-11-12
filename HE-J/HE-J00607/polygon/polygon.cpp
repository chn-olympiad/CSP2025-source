#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N =5003,mod=998244353;
int n,sum,ans,a[N],mx=-N;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	std::cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],mx=std::max(a[i],mx),sum+=a[i];
	if(mx==1){
		for(int i=1;i<=n-2;i++)
			ans+=i*(n-i-1)%mod,ans%=mod;
		std::cout<<ans%mod;
		return 0;
	}
	std::cout<<(sum-mx-1)%mod;
	return 0;
}
