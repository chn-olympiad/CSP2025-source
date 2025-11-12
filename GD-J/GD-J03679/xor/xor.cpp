#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,k;
int dp[N]={0};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&dp[i]);
	}
	if(k==0){
		int dai[N]={0}; 
		for(int i=1;i<=n;i++){
			dai[i]=dp[i];
		}
		sort(dai+1,dai+n+1);
		bool flag=1;
		for(int i=2;i<=n;i++){
			if(dai[i]!=dai[i-1]){
				flag=0;
				break;
			}
		}
		if(flag){
			if(dp[n]==0){
				cout<<n;
				return 0;
			}
			else{
				cout<<n/2;
			}
		}
		else{
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(dp[i]==0){
					cnt++; 
				}else{
					if(dp[i]==dp[i+1]){
						cnt++;
					}
				} 
			}
			cout<<cnt;
			return 0;
		}
	}
	else if(k==1){
		sort(dp+1,dp+n+1);
		bool flag=0;
		for(int i=2;i<=n;i++){
			if(dp[i]!=dp[i-1]){
				flag=1;
				break;
			}
		}
		if(flag){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(dp[i]==1){
					cnt++;
				}
			}
			cout<<cnt;
			return 0;
		}
		else{
			if(dp[1]==1 && dp[n]==1){
				cout<<n;
				return 0;
			}
			cout<<0;
			return 0;
		}
	}
	
	
}
