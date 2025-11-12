//GZ-S00333 贵州省实验中学 王焕坤
#include<bits/stdc++.h>
using namespace std;
int dp[100005][5];
int s[100005][5];
int t,n;
int cnt[100005][6];
int fmax(int a,int b){
	int t=0;
	int l=0;
	for(int i=1;i<=3;i++){
		if(t<s[a][i]&&i!=b&&cnt[a][i]<=n/2){
			t=s[a][i];
			l=i;
		}
	}
	return l;
}
int solve(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(cnt[i-1][j]<n/2){
				if(dp[i-1][j]+s[i][j]>dp[i][j-1]){
					dp[i][j]=dp[i-1][j]+s[i][j];
					cnt[i][j]=cnt[i-1][j]+1;
				}
				else{
					dp[i][j]=dp[i][j-1];
					cnt[i][j]=cnt[i-1][j];
				}
			}
			else{
				if(dp[i-2][j]+s[i-1][fmax(i-1,j)]+s[i][j]>dp[i][j-1]){
					dp[i][j]=dp[i-2][j]+s[i-1][fmax(i-1,j)]+s[i][j];
					cnt[i-1][fmax(i-1,j)]++;
					cnt[i][j]=cnt[i-2][j]+1;
				}
				else{
					dp[i][j]=dp[i][j-1];
					cnt[i][j]=cnt[i-1][j];
				}
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		memset(cnt,0,sizeof(cnt));
		memset(s,0,sizeof(s));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i][1]>>s[i][2]>>s[i][3];
		}
		solve(n);
		cout<<dp[n][3]<<endl;
	}
	return 0;
} 
