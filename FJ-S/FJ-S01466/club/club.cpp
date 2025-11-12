#include<bits/stdc++.h>
using namespace std;
const int N=205,MAXN=1e5+5;
int t,n,a1[MAXN],a2[MAXN],a3[MAXN],dp[N][N][N],mx,ans=0;
bool f1=1,f2=1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		memset(dp,0,sizeof dp);
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a2[i]!=0)f1=0;
			if(a3[i]!=0)f2=0;
		}
		ans=0;
		if(f1&&f2){
			sort(a1+1,a1+n+1);
			for(int i=1;i<n/2;i++)ans+=a1[i];
			cout<<ans<<"\n";
			continue;
		}else if(f2){
			
		}else if(n>200&&n<=1e5){
			for(int i=1;i<=n;i++){
				ans+=max(a1[i],max(a2[i],a3[i]));
			}
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					if(j>0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a1[i]);
					if(k>0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a2[i]);
					if(i-j-k<=n/2&&i-j-k>0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a3[i]);
				}
			}
		}
		mx=0;
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				int k=n-i-j;
				if(k<=n/2)mx=max(mx,dp[n][i][j]);
			}
		}
		cout<<mx<<"\n";
	}
	return 0;
}
