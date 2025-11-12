#include<bits/stdc++.h>
using namespace std;
long long n,a[10005],b,c,dp[100005],wd,ans,s;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		s=0;
		for(int j=a[i]+1;j<=5001;j++){
			s+=dp[j];
		}
		s+=wd;
		ans+=s;
		ans%=998244353;
		wd*=2;
		for(int j=5001;j>5001-a[i];j--){
			wd+=dp[j];
		}
		wd%=998244353;
		for(int j=5001;j>=a[i];j--){
			dp[j]+=dp[j-a[i]];
			dp[j]%=998244353;
		}
	}
	cout<<ans;
	return 0;
}
