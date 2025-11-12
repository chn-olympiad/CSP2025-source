#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],dp[20005][23005],ans;
bool b[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++){
		cin>>a[i];
		dp[i][i]=a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			dp[i][j]=dp[i][j-1]^dp[j][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(dp[i][j]==k){
				b[j]=1;
				break; 
			}
		}
	}
	for(int i=n-1;i>=0;i--){
		if(b[i]==1){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
} 
