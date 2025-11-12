#include<bits/stdc++.h>
using namespace std;
int a[100005];
long long dp[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	int ma=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ma=max(ma,a[i]);
	}
	if(ma==1&&n>1e3){
		int s=0;
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]){
					s++;
				}
			}
			cout<<s;
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]){
					if(a[i-1]==1){
						a[i]=0;
						s++;
					}
				}
				else{
					s++;
				}
			}
			cout<<s;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(i==1){
			if(a[1]==k){
				dp[1]=1;
			}
			continue;
		}
		dp[i]=dp[i-1];
		int pre=a[i];
		for(int j=i-1;j;j--){
			pre^=a[j];
			if(pre==k){
				dp[i]=max(dp[i],dp[j-1]+1);
				break;
			}
		}
		if(a[i]==k){
			dp[i]=max(dp[i],dp[i-1]+1);
			continue;
		}
	}
	cout<<dp[n];
}
