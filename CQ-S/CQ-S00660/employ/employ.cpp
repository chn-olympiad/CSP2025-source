#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=4e2+5,mod=998244353;
int n,m,a[N],b[N],dp[20][(1<<18)+5][20],cnt1[N],sum[N],flag;
char x;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)cin >> x,a[i]=(x-'0'),sum[i]=sum[i-1]+a[i];
	for(int i = 1;i <= n;i++)cin >> b[i],flag|=(b[i]==0);
	if(n<=18){
		dp[0][0][0]=1;
		for(int i = 1;i <= (1<<n);i++)cnt1[i]=cnt1[i>>1]+(i&1);
		for(int i = 0;i < n;i++){
			for(int j = 0;j < (1<<n);j++){
				if(cnt1[j]!=i)continue;
				for(int k = 0;k <= i;k++){
					if(!dp[i][j][k])continue;
					for(int l = 0;l < n;l++){
						if(j&(1<<l))continue;
						int now=(j|(1<<l));
						if(i-k<b[l+1]&&a[i+1]==1)dp[i+1][now][k+1]=(dp[i+1][now][k+1]+dp[i][j][k])%mod;
						else dp[i+1][now][k]=(dp[i+1][now][k]+dp[i][j][k])%mod;
					}
				}
			}		
		}
		int ans=0;
		for(int i = m;i <= n;i++)ans=(ans+dp[n][(1<<n)-1][i])%mod;
		cout << ans;
	}else{
		if(m==n){
			if(sum[n]!=n||flag)cout << "0";
			else{
				int ans=1;
				for(int i = 1;i <= n;i++)ans=ans*i%mod;
				cout << ans;
			}
			return 0;
		}else if(m==1){
			
		}
	}
	return 0;
}//ÉñÃØdp
//

