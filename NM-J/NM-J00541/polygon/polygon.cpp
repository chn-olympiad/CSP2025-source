#include<bits/stdc++.h>
using namespace std;
int n;
long long int a[5005],dp[5005],k = 1,ans = 0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a,a+n+1,greater<int>());
	for(int i=3;i<=n;i++){
		for(int j=1;j<=i;j++){
			dp[i] = a[i]+a[j];
			if(dp[i]>a[1]*2) ans++;
		}
	}
	ans = ans%998%244%353;
	cout<<ans;
	return 0;
}
