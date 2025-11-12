#include <bits/stdc++.h>
using namespace std;

long long mod=998244353;
long long dp[6005][5];
long long rdp[6005][5];
int a[6005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	long long ans=0;
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<=5001;j++){
			ans=(ans+dp[j][2]+dp[j][3])%mod;
		}
		memset(rdp,0,sizeof(rdp));
		for(int j=0;j<=5001;j++){
			for(int z=0;z<4;z++){
				rdp[j][z]=dp[j][z];
			}
		}
		for(int z=1;z<4;z++){
			for(int j=a[i];j<=5000;j++){
				rdp[j][z]=(rdp[j][z]+dp[j-a[i]][z-1])%mod;
			}
			for(int j=5001;j<=5000+a[i];j++){
				rdp[5001][z]=(rdp[5001][z]+dp[j-a[i]][z-1])%mod;
			}
		}
		rdp[5001][1]+=dp[5001][0];
		rdp[5001][2]+=dp[5001][1];
		rdp[5001][3]+=dp[5001][2];
		rdp[5001][3]+=dp[5001][3];
		for(int j=a[i];j<=5000;j++) rdp[j][3]=(rdp[j][3]+dp[j-a[i]][3])%mod;
		for(int j=5001;j<=5000+a[i];j++) rdp[5001][3]=(rdp[5001][3]+dp[j-a[i]][3])%mod;
		for(int j=0;j<=5001;j++){
			for(int z=0;z<4;z++){
				dp[j][z]=rdp[j][z];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
