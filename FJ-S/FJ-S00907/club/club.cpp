#include<bits/stdc++.h>
using namespace std;
struct sy{
	int bj,cj;
};
int n;
sy s[100005];
int dp[205][105][105];
bool cmp1(sy a,sy b){
	return max(a.bj,a.cj)>max(b.bj,b.cj);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(dp,-63,sizeof(dp));
		cin>>n;
		long long ans=0;
		for(int i=1;i<=n;i++){
			long long a,b,c;
			cin>>a>>b>>c;
			ans+=a;
			s[i].bj=b-a;
			s[i].cj=c-a;
		}
		sort(s+1,s+n+1,cmp1);
		if(n<=200){
			dp[1][0][0]=s[1].cj;
			dp[1][1][0]=0;
			dp[1][0][1]=s[1].bj;
			for(int i=2;i<=n;i++){
				for(int j=0;j<=min(n/2,i);j++){
					for(int k=0;k+j<=i;k++){
						if(j!=0){
							dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]);
						}
						if(k!=0){
							dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+s[i].bj);
						}
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+s[i].cj);
					}
				}
			}
			int cnt=-0x3f3f3f3f;
			for(int i=0;i<=n;i++){
				for(int j=0;j<=n;j++){
					if(i+j>=n/2&&i<=n/2&&j<=n/2){
						cnt=max(cnt,dp[n][i][j]);
					}
				}
			}
			cout<<ans+cnt<<endl;
		}
		else{
			for(int i=1;i<=n/2;i++)
				ans+=s[i].bj;
			cout<<ans<<endl;
			continue;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
