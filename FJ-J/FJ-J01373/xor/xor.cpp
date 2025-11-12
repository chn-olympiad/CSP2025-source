#include<bits/stdc++.h>
using namespace std;
long long n,k,ans,s=1;
long long a[500010],dp[1010][1010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][i]=a[i];
	}for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			dp[i][j]=a[i]^dp[i-1][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=s;j<=i;j++){
			if(dp[i][j]==k){
				ans++;
				s=i+1;
				break;
			} 
		}
	}
	cout<<ans;
	return 0;
} 
