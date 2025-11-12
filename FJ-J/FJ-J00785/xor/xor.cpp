#include<bits/stdc++.h>
using namespace std;
int n,k,a[105],dp[105][105],he=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			dp[i][j]=a[i]^a[j];
			if(dp[i][j]==k) he++;
			for(int k=1;k<j;k++){
				if(dp[j][k]==k) he++;
			}
		}
	}
	cout<<he;
	return 0;
}
