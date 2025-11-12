#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[5200],ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=2){
		cout<<0;
		return 0;
	}
	sort(a+1,a+1+n);
	if(n==3){
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	ans=n+1;
	for(int i=3;i<=n-2;i++){
		for(int j=1;j<=n-i+1;j++){
			ans=(ans+(1+j)*j/2)%mod;
		}
	}
	cout<<ans;
	return 0;
}
