#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5005],ans=0,mod=998244353;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		if((a[1]+a[2]+a[3])>2*a[3]){
			ans++;
		}
		cout << ans;
		return 0;
	}
	if(a[n]==1){
		for(int i=3;i<=n;i++){
			int ls=1;
			for(int j=1;j<=i;j++){
				ls*=(n-j+1);
				ls/=j;
			}
			ls%=mod;
			ans+=ls;
			ans%=mod;
		}
		cout << ans;
		return 0;
	}
	
	return 0;
} 
