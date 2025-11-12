#include<bits/stdc++.h>
using namespace std;
long long n,k,a[5000005];
long long ans=0;
bool ch(long long l,long long r){
	ans^=a[r];
	if(ans==k) return true;
	else return false;
}
long long dp[5000005];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ans=0;
		for(int j=i;j<=n;j++){
			if(ch(i,j)){
				dp[j]=max(max(dp[j-1],dp[j]),dp[i-1]+1);
			}else dp[j]=max(dp[j],dp[j-1]);
		}
	}
	cout<<dp[n];
	return 0;
}
