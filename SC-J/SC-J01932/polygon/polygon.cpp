#include<bits/stdc++.h>
using namespace std;
long long n;const long long N=5005,mod=998244353;
long long dp[N*N];
long long a[N];
long long ans;
long long maxx;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=i*maxx;j>=0;j--){
			if(dp[j]){
				dp[j+a[i]]+=dp[j];
				dp[j+a[i]]%=mod;
				if(j+a[i]>=2*a[i]+1){
					ans+=dp[j];
					ans%=mod;
				}
			}
		}
		dp[a[i]]+=1;
		dp[a[i]]%=mod;
	}
	cout<<ans;
	return 0;
}