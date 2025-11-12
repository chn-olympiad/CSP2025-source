#include<bits/stdc++.h>
using namespace std;
int a[100005],dp[1005],b[1005][1005],n,k,mx,cnt,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		if(a[i]==0) cnt++;
	}
	if(mx<=1){
		if(k==0) cout<<cnt<<endl;
		else if(k==1) cout<<n-cnt<<endl;
		else cout<<0<<endl;
	}else{
		for(int i=1;i<=n;i++){
			b[i][i]=a[i];
			for(int j=i+1;j<=n;j++){
				b[i][j]=a[j]^b[i][j-1];
			}
		}
		dp[1]=0;
		for(int i=1;i<=n;i++){
			dp[i+1]=max(dp[i+1],dp[i]);
			for(int j=i;j<=n;j++){
				if(b[i][j]==k){
					dp[j+1]=max(dp[j+1],dp[i]+1);
				}
			}
			ans=max(dp[i],ans);
		}
		cout<<max(ans,dp[n+1])<<endl;
	}
	return 0;
}
