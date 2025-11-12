#include<bits/stdc++.h>
using namespace std;
int dp[6][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int price[n][3];
		int max[n];
		for(int j=0;j<n;j++){
			cin>>price[j][0]>>price[j][1]>>price[j][2];
			max[j]=price[j][0];
		}
		for(int j=0;j<n;j++){
			for(int k=0;k<n-1;k++){
				if(max[k]<max[k+1]){
					swap(max[k],max[k+1]);
				}
			}
		}
		int ans=0;
		for(int j=0;j<n/2;j++){
			ans+=max[j];
		}
		cout<<ans<<endl;
	}
	return 0;
}
