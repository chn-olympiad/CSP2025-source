#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[505],lp[505],cnt;
long long ans,dp[1000005][20];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	int len=s.size()-1;
	for(int i=0;i<=len;i++)lp[i+1]=s[i]-'0';
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=18){
		dp[0][0]=1;
		for(int i=1;i<(1<<n);i++){
			cnt=0;
			for(int j=0;j<n;j++)if((1<<j)&i)cnt++;
			for(int j=0;j<n;j++){
				if((1<<j)&i){
					for(int k=0;k<=n;k++){
						if(c[j+1]>k&&lp[cnt]!=0)dp[i][k]+=dp[(1<<j)^i][k];
						else dp[i][k+1]+=dp[(1<<j)^i][k];
						dp[i][k]%=mod;
					}
				}
			}
		}
		for(int i=0;i<=n-m;i++)ans+=dp[(1<<n)-1][i],ans%=mod;
		cout<<ans<<"\n";
	}
	return 0;
}
