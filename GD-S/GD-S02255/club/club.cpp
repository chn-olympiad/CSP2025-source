#include<bits/stdc++.h>
using namespace std;
int m;
long long n,s[100005][5],dp[100005][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.txt","w",stdout);
	cin>>m;
	for(int q=1;q<=m;q++){
		memset(s,0,sizeof(s));
		memset(dp,0,sizeof(dp));
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>s[i][j];
			}
		}
		if(n==2){
			long long ans=0; 
			for(int i=1;i<=3;i++){
				long long max1=0;
				for(int j=1;j<=3;j++){
					if(j!=i)
					max1=max(max1,s[2][j]);
					ans=max(ans,max1+s[1][i]);
				}
			}
			cout<<ans<<endl;
			continue;
		}
		int p1=0;
		for(int i=1;i<=n/2;i++){
			for(int j=1;j<=3;j++){
				long long max1=0;
				for(int o=1;o<=3;o++)
				max1=max(dp[i-1][o],max1);
				dp[i][j]=max1+s[i][j]; 
			}
		}
		for(int i=n/2+1;i<=n;i++){
			for(int j=1;j<=3;j++){
				long long max1=0;
				for(int o=1;o<=3;o++)
				if(o!=j) max1=max(dp[i-1][o],max1);
				dp[i][j]=max(dp[i-n/2-1][j]+s[i-1][j]+s[j][j],max(dp[i-n/2][j]+s[i][j],max1+s[i][j])); 
			}
		}
		long long ans=0;
		for(int i=1;i<=3;i++){
			ans=max(ans,dp[n][i]);
		}
		cout<<ans<<endl;
	}
	return 0;
} 
