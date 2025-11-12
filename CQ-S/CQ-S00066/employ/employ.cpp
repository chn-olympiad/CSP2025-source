#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=18;
const int mod=998244353;
int n,m;
int a[MAXN+5];
char s[MAXN+5];
int sum[MAXN+5];
int dp[3][MAXN+1][(1<<18)+5];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	//cout<<(int)(pow(2,18)*19*19);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++){
		for(int k=(1<<n)-1;k>=0;k--){
			for(int j=1;j<=n;j++){
				if((k&(1<<(j-1)))==0){
					continue;
				}
				for(int p=i-1;p>=0;p--){
					if(a[j]<=(i-p-1)||s[i]=='0'){
						//cout<<"i="<<i<<" "<<j<<" "<<p<<" "<<k<<" "<<k-(1<<(j-1))<<" "<<dp[i-1][p][k-(1<<(j-1))]<<endl;
						dp[i&1][p][k]+=dp[((i&1)^1)][p][k-(1<<(j-1))];
						dp[i&1][p][k]%=mod;
					}else{
					//	cout<<"p="<<i<<" "<<j<<" "<<p<<" "<<k<<" "<<k-(1<<(j-1))<<" "<<dp[i-1][p][k-(1<<(j-1))]<<endl;
						dp[i&1][p+1][k]+=dp[((i&1)^1)][p][k-(1<<(j-1))];
						dp[i&1][p+1][k]%=mod;
					}
				}
			}
		}
	}
	for(int i=m;i<=n;i++){
		//cout<<"i="<<i<<" "<<dp[n][i][(1<<n)-1]<<endl;
		ans+=dp[n&1][i][(1<<n)-1];
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
