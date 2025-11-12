#include<bits/stdc++.h>
using namespace std;
unsigned long long n,k,a[1000100],b[1000010],dp[1000010],lst,y,u;//lst:上一个区间结尾 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		b[i]=a[i]^b[i-1];
	}
	lst=0;
	for(int i=1;i<=n;i++){
		u=0;
		for(int j=lst+1;j<=i;j++){
			y=b[i]^b[j-1];
			if(y==k){
				if(dp[j-1]+1>=dp[i]){
					dp[i]=dp[j-1]+1;
					u=1;
				}
			}
		}
		if(u) lst=i;
		dp[i]=max(dp[i],dp[i-1]);
	}
	cout<<dp[n];
	return 0;
}
