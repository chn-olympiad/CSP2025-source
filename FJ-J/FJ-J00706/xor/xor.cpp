#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
#define L long long
L a[N],dp[N];
int main(){
	//freopen("xor4.in","r",stdin);
	//freopen("xor4.out","w",stdout);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	L n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n>=100000 && k<=1){
		if(k==0){
			L ans=0;
			for(int i=2;i<=n;i++){
				if(a[i]==a[i-1] && a[i]==1){
					ans++;
				}
				else if(a[i]==0) ans++;
			}
			cout<<ans;
		}
		else{
			L ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					ans++;
				}
			}
			cout<<ans;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		L nw=i-1,ans=a[i];
		if(a[i]==k){
			dp[i]=dp[i-1]+1;
			continue;
		}
		for(int j=nw;j>=1;j--){
			ans^=a[j];
			if(ans==k){
				dp[i]=max(dp[i],dp[j-1]+1);
			}
		}
		dp[i]=max(dp[i],dp[i-1]);
	}
	L ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
