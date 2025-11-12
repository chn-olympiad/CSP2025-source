#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5010];
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		int maxv=0,kl=0;
		for(int i=1;i<=n;i++){
			maxv=max(a[i],maxv);
			kl+=a[i];
		}
		if(kl>maxv*2){
			cout<<1<<endl;
			return 0;
		}
	} else {
		int ans=0;
		for(int i=n-2;i>=1;i--){
			ans+=(n-2+1)*(n-2)/2;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
    return 0;
}
