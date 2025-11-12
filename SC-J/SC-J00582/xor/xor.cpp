#include<bits/stdc++.h>
using namespace std;
//思路：使用差分处理所有异或结果
long long n,k,num[500001],dp[500001],maxc;
/*4 2
2 1 0 3*/
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>num[i];
	}
	for(long long i=1;i<=n;i++){
		long long e=0;
		for(long long j=i;j<=n;j++){
			e^=num[j];
			if(e==k){
				dp[j]=max(dp[i-1]+1,dp[j]);
			}
			else{
				dp[j]=max(dp[i-1],dp[j]);
			}
		}
	}
	cout<<dp[n];
}