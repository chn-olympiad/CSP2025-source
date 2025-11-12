#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long a[500005];
int dp[500005][2][2];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool f=true,t=true;
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0){
			f=false;
		}
		if((a[i]!=0)&&(a[i]!=1)){
			t=false;
		}
	}
	if(f==true){
		cout<<n/2;
		return 0;
	}
	if(t==true){
		int x=0;
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					x++;
				}
			}
	    }
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					x++;
				}
				else if(a[i]==1&&a[i+1]==1){
					x++;
					i++;
				}
			}
		}
		cout<<x;
		return 0;
	}
//	for(int i=1;i<=n;i++){
//		if(a[i]==k){
//			for(int d=0;d<=sum;d++){
//				dp[i][0]=x+1;
//				if(a[i]^d!=k){
//					dp[i][d^a[i]]=dp[i-1][d];
//				}
//			}
//		}
//		else if(i!=1){
//			for(int d=0;d<=sum;d++){
//				if(d^a[i]==k){
//					dp[i][0]=x+1;
//				}
//				else{
//					dp[i][d^a[i]]=dp[i-1][d];
//				}
//			}
//		}
//		for(int d=1;d<=sum;d++){
//			x=max(x,dp[i][d]);
//		}
//	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			dp[i][0][1]=max(dp[i-1][0][1],dp[i-1][0][0])+1;
			dp[i][1][1]=0;
			dp[i][0][0]=max(dp[i-1][0][1],dp[i-1][0][0]);
			dp[i][1][0]=0;
		}
		else if(i!=1){
			if(dp[i-1][1][0]^a[i]==k){
				dp[i][0][1]=max(dp[i][0][1],dp[i-1][0][0]+1);
				dp[i][1][1]=0;
				dp[i][0][0]=max(dp[i][0][0],dp[i-1][0][0]);
				dp[i][1][0]=0;
			}
			else if(dp[i-1][1][1]^a[i]==k){
				dp[i][0][1]=max(dp[i][0][1],dp[i-1][0][1]+1);
				dp[i][1][1]=0;
				dp[i][0][0]=max(dp[i][0][0],dp[i-1][0][1]);
				dp[i][1][0]=0;
			}
			else{
				dp[i][0][1]=max(dp[i-1][0][1],dp[i-1][0][0]);
				if(dp[i-1][0][1]>=dp[i-1][0][0]){
					dp[i][1][1]=dp[i-1][1][1]^a[i];
				}
				else{
					dp[i][1][1]=dp[i-1][1][0]^a[i];
				}
				dp[i][0][0]=max(dp[i-1][0][1],dp[i-1][0][0]);
				dp[i][1][0]=0;
			}
		}
	}
	cout<<max(dp[n][0][0],dp[n][0][1]);
//	for(int i=1;i<=n;i++){
//		cout<<dp[i][0][1]<<' '<<dp[i][0][0];
//		cout<<endl;
//	}
	return 0;
}
