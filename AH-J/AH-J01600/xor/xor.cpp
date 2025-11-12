#include<bits/stdc++.h>
using namespace std;
int n,k,dp[1005][1005];
int a[1005],e[1005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int yh=0;
		for(int j=i;j<=n;j++) {
			yh=yh|a[j];
			if(yh==k){
				e[i]=min(e[i],j);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(e[i]!=0){	
			for(int j=0;j<=n;j++){
				dp[i][j]=dp[i-1][j];
				for(int x=0;x<i;x++){
					dp[i][e[i]]=max(dp[i][j],dp[i-1][x]+1);
				}
				ans=max(ans,dp[i][j]);
			}
		}
	}
	cout<<ans<<endl;
}
