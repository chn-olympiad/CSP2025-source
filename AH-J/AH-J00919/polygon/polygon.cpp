#include<bits/stdc++.h>
using namespace std;
int n,k,a[5005],dp[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	int ans=0,mod=998244353;
	sort(a+1,a+n+1);
	for(int mi=n;mi>=1;mi--){
		memset(dp,0,sizeof(dp));
		dp[a[mi]]=1;
		for(int i=1;i<mi;i++){
			for(int j=sum;j>=a[i];j--){
				dp[j]+=dp[j-a[i]];
				dp[j]%=mod;
			}
		}
		int mx=0;
		for(int i=a[mi]*2+1;i<=sum;i++){
			mx+=dp[i];
			mx%=mod;
		}
		ans+=mx;
		ans%=mod;
		sum-=a[mi];
	}
	cout<<ans;
	return 0;
}
