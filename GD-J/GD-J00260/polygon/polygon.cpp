#include<bits/stdc++.h>
using namespace std;
long long n,a[50005],dp[50005],cnt,ans=0;
int main(){
	freopen("polygon","r",stdin);
	freopen("polygon","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=dp[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) cout<<dp[i]<<" ";
	cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			cnt=dp[i]+a[j];
			if(cnt>2*a[j]){
				ans++;
				cout<<cnt<<" "<<a[j]<<endl;
			}
		} 
	}
	cout<<ans%998%244%353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
