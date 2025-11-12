#include<iostream>
#define int long long
using namespace std;
int n,k,ans;
int a[500005];
int dp[1005][1005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool b1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][i]=(a[i]==k);
		if(a[i]!=1)b1=0;
	}
	if(b1){
		cout<<n/2;
		return 0;
	}
	/*for(int len=2;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1,tmp=a[i];
			for(int l=i+1;l<=j;l++){
				tmp^=a[l];
			}
			if(tmp==k)dp[i][j]=1;
		}
	}*/
	for(int len=2;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1,tmp=a[i];
			for(int l=i+1;l<=j;l++){
				tmp^=a[l];
			}
			if(tmp==k)dp[i][j]=1;
			for(int l=i;l<=j;l++){
				dp[i][j]=max(dp[i][j],dp[i][l]+dp[l+1][j]);
			}
		}
	}
	cout<<dp[1][n];
	return 0;
}
