#include<bits/stdc++.h>
using namespace std;
int n,a[500020],dp[1005][1005],val[1005],k;

int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k)dp[i][i]=1;
		val[i]=int(val[i-1]^a[i]);
		if(val[i]==k)dp[1][i]=1;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
				if(int(val[j]^val[i])==k)dp[i+1][j]=1;
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			for(int mid=j+1;mid<j+i-1;mid++){
//				if(dp[j][mid]+dp[mid+1][j+i]>dp[j][j+i])cout<<"//"<<j<<mid<<"+"<<mid+1<<j+i<<"=="<<dp[j][mid]+dp[mid+1][j+i]<<"\\";
				dp[j][j+i-1]=max(dp[j][j+i-1],dp[j][mid-1]+dp[mid][j+i-1]);
			}
		}
	}
	
	cout<<dp[1][n];
	
	return 0;
}

