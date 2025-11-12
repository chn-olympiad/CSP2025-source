#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][3];
int dp[N][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
		}
		int ans=0;
		for(int i=0;i<n/2;i++){
			int num=0,num2=0;
			for(int j=0;j<n;j++){
				if(num<a[j][0]){
					num=a[j][0];
					num2=j;
				}
			}
			ans+=num;
			a[num2][0]=0;
		}
		cout<<ans<<endl;
//		for(int i=0;i<n;i++){
//			for(int j=0;j<3;j++){
//				dp[i][j]=max(dp[i][j],dp[i][j-1]+a[i][j]);
//			}
//		}
//		cout<<dp[n-1][2]<<endl;
	}
	return 0; 
}
