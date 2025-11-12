#include<bits/stdc++.h>
using namespace std;
int dp[5000500];
int a[5000500];
int yh[3050][3050];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,tt;
	cin>>n>>tt;
	bool ttt=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1){
			ttt=false;
		}
	}
	if(ttt){
		int ans=0;
		if(tt==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					ans++;
				}
			}
			cout<<ans;
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans++;
				}
			}
			int g=1;
			while(a[g]==0){
				g++;
			}
			for(int i=g,j=g;j<=n;){
				while(a[j+1]==1){
					j++;
				}
				ans+=(j-i+1)/2;
				j++;
				while(a[j]==0&&j<=n){
					j++;
				}
				i=j;
			}
			cout<<ans;
		}
	}else{
		for(int i=0;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=i;k<=j;k++){
					yh[i][j]^=a[k];
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				for(int k=j;k<=i;k++){
					if(yh[j][k]==tt){
						dp[i]=max(dp[j-1]+1,dp[i]);
					}else{
						dp[i]=max(dp[j-1],dp[i]);
					}
				}
		 	}
		}
		cout<<dp[n];
	}
	return 0;
}