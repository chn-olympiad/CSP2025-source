#include<bits/stdc++.h>
using namespace std;
int t;
int a[100005],b[100005],c[100005],v[100005];
int dp[100005][100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			v[i]=max(max(a[i],b[i]),c[i]);
		}
		for(int i=1;i<=3;i++){
			for(int j=1;j<=n/2;j++){
				if(j>n/2){
					dp[i][j]=max(dp[i-1][j],dp[i-1][j]+v[i]);
				}
				else dp[i][j]=dp[i-1][j];
			}
		}
		cout<<dp[n/2][3]<<endl;
	}
	return 0; 
} 
