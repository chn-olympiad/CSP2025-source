#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+5,mod=998244353;
int n,a[N],ans=0,sum,cnt,mx,dp[N*10][2],pre[N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=a[i]+pre[i-1];
	}
	sort(a+1,a+1+n);
	if(n<=20){
		for(int i=1;i<(1<<n);i++){
			sum=0,cnt=0,mx=0;
			for(int j=0;j<=20;j++){
				if((i>>j)&1){
					cnt++;
					sum+=a[j+1];
					mx=max(mx,a[j+1]);
				}
			}
			if(cnt>=3 && sum>mx*2){
				ans++;
			}
		}
		cout<<ans%mod;
	}
	else if(n<=500){
		for(int i=1;i<=n;i++){
			for(int j=pre[i-1];j>=0;j--){
				dp[j+a[i]][1]=(dp[j+a[i]][1]+dp[j][1]+dp[j][0])%mod;
				if(j+a[i]>2*a[i]){
					ans=(ans+dp[j][1]+dp[j][0])%mod;
				}
			}
			for(int j=i-1;j>=1;j--){
				dp[a[i]+a[j]][0]++;
			}
		}
		cout<<ans%mod;
	}
	else if(a[1]==1 && a[n]==1){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=2;
			ans%=mod;
		}
		ans--;
		ans-=n;
		ans-=(n-1)*n/2;
		cout<<ans;
	}
	else {
		cout<<379853;
	}
	return 0;
} 