#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int sum[500005];
//int dp[500005][500005];
int dp[1005][1005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int mx=-1e9;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		sum[i]=(sum[i-1]^a[i]);
	}
	if(mx==1){
		int cnt=0;
		if(k==0){
			int l=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					l++;
				}else{
					cnt+=l/2;
					l=0;
					cnt++;
				}
			}
			cnt+=l/2;
			cout<<cnt;
		}else if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					cnt++;
				}
			}
			cout<<cnt;
		}else{
			cout<<0;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if((sum[i]^sum[j-1])==k){
//				cout<<i<<' '<<j<<'\n';
				dp[j][i]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=i;k<=j;k++){
				dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
			}
		}
	}
	cout<<dp[1][n];
	return 0;
}