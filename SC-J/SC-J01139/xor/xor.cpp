#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005],dp[500005],now;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int flag=1,cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=0;	
		}
	}
	if(flag){
		cout<<n/2<<endl;
	}else{
		if(a[1]==k) dp[1]=1;
		else{
			dp[1]=0;
			now=a[1];
		}
		for(int i=2;i<=n;i++){
			if(a[i]==k||(a[i]^now)==k){
				dp[i]=dp[i-1]+1;
				now=0;
			}else{
				dp[i]=dp[i-1];
				now^=a[i];
			}
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}