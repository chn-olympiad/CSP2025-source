#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen(".in","r",stdin);
	freopen(",out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int all=0;
	cin>>all;
	int result[all]={};
	for(int i=0;i<all;i++){
		int n;
		cin>>n;
		int arr[n+1][3+1]={0};
		for(int j=0;j<n;j++){
			cin>>arr[j+1][1]>>arr[j+1][2]>>arr[1+j][3];
		}
		int dp[n+1][4]={0};
		int dp1[3][3]={0};
		for(int j=0;j<3;j++){
			dp1[j][1]=INT_MAX;
		}
		int kong=0;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){


				if(dp1[k-1][0]<n/2){
					if(dp[j-1][k]+arr[j][k]>=dp[j][k-1]+arr[kong][k]){
						dp[j][k]=dp[j-1][k]+arr[j][k]+arr[kong][k];
						dp1[k-1][0]++;
						if(dp1[k-1][1]>=arr[j][k]){
							dp1[k-1][1]=arr[j][k];
							dp1[k-1][2]=j;

						}


					}
					else{
						dp[j][k]=dp[j][k-1];
					}
				}
				else{
					if(arr[j][k]>=dp1[k-1][1]){
						if(k!=3)
							dp[j][k]=arr[j][k]+dp[j-1][k]-dp1[k-1][1]+arr[j-1][k-1];

						else{
							dp[j][k]=max(arr[j][k]+dp[j-1][k]-dp1[k-1][1]+arr[j][k-2],arr[j][k]+dp[j-1][k]-dp1[k-1][1]+arr[j][k-1]);
						}
						kong=dp1[k-1][2];
						dp1[k-1][2]=j;
						dp1[k-1][1]=arr[j][k];
					}
					else{
						if(k!=3)
							dp[j][k]=dp[j-1][k]+arr[j][k-1];

						else{
							dp[j][k]=dp[j-1][k]+max(arr[j][k-1],arr[j][k-2]);
						}
					}
				}
			}

		}
		result[i]=dp[n][3]+1;

	}
	for(int i=0;i<all;i++){
		cout<<result[i]<<endl;
	}

	return 0;
}
