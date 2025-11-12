#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5005],dp[10005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	dp[0]=1;
	long long cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=5001;j>=0;j--){
			dp[j+a[i]]+=dp[j];
			dp[j+a[i]]%=mod;
			if(j>a[i]){
				cnt+=dp[j];
				cnt%=mod;
			}
		}for(int j=5002;j<=10001;j++){
			dp[5001]+=dp[j];
			dp[5001]%=mod;
			dp[j]=0;
		}
	}cout<<cnt;
	return 0;
} 