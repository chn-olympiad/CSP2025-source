#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
const int MAXN=5e5+5;
int a[MAXN],cntx[MAXN],dp[MAXN][2];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cntx[0]=0;
	for(int j=1;j<=n;j++){
		cin>>a[j];
		cntx[j]=a[j]^cntx[j-1];
	}
	for(int r=1;r<=n;r++){
		for(int l=r;l>=1;l--){
			int q=cntx[r]^cntx[l-1];
			if(q==k){
				dp[r][1]=max(dp[r][1],dp[l-1][0]+1);
				dp[r][1]=max(dp[r][1],dp[l-1][1]+1);
			}
			dp[r][0]=max(dp[r][0],dp[l-1][0]);
			dp[r][0]=max(dp[r][0],dp[l-1][1]);
		}
	}
	cout<<max(dp[n][0],dp[n][1]);
	return 0;
} 
