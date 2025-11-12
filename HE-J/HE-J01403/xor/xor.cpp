#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005],dp[1005][1005];
int ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			a[i]=-1;
			dp[i][i]=-1;
		}
		else dp[i][i]=a[i];
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i+l-1<=n;i++){
			int j=i+l-1;
			bool f=1;
			for(int k1=i;k1<=j;k1++)
				if(a[k1]==-1){
					f=0;
					break;
				}
			if(f){
				dp[i][j]=dp[i][j-1]^a[j];
				if(dp[i][j]==k){
					ans++;
					for(int k1=i;k1<=j;k1++)a[k1]=-1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
