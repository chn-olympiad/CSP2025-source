#include<bits/stdc++.h>
using namespace std;
int dp[201][201][201];
int a[200001][3];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ans = 0;
		memset(dp,0,sizeof dp);
		if(n<=200){
			for(int i = 1;i<=n;i++){
				for(int j = 1;j<=3;j++){
					cin>>a[i][j];
				}
			}
			for(int i = 0;i<=n/2;i++){
				for(int j = 0;j<=n/2;j++){
					for(int k = 0;k<=n/2;k++){
						if(i+j+k>n){
							break;
						}
						dp[i][j][k] = max(dp[max(i-1,0)][j][k]+(i>0?a[i+j+k][1]:0),max(dp[i][max(j-1,0)][k]+(j>0?a[i+j+k][2]:0),dp[i][j][max(k-1,0)]+(k>0?a[i+j+k][3]:0))); 
	//					cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<endl;
						if(i+j+k == n){
							ans = max(ans,dp[i][j][k]);
						}
					}
				}
			}
		
		}
		else{
			bool flag = 0;
			for(int i = 1;i<=n;i++){
				for(int j = 1;j<=3;j++){
					cin>>a[i][j];
					if(j == 2&&a[i][j]!=0){
						flag = 1;
					}
				}
			}
			if(!flag){
				int x[100005];
				for(int i = 1;i<=n;i++){
					x[i] = a[i][1];
				}
				sort(x+1,x+1+n,cmp);
				for(int i = 1;i<=n/2;i++){
					ans+=x[i];
				}
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}
