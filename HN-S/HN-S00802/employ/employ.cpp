#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
string s;
int c[20];
int dp[(1<<18)+5][20];
int w[505];
const int mod=998244353;
int getsum(int x){
	int sum=0;
	while(x){
		sum+=x%2;
		x/=2;
	}return sum;
}
int frac(int n){
	int ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=mod;
	}return ans;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n<=18){
		cin>>s;
		for(int i=0;i<n;i++)cin>>c[i];
		dp[0][0]=1;
		for(int i=1;i<(1<<n);i++){
			int x=getsum(i);
			for(int j=0;j<n;j++){
				if((i&(1<<j))==0)continue;
				for(int k=0;k<=n;k++){
					if(k>=c[j])dp[i][k+1]+=dp[i^(1<<j)][k],dp[i][k+1]%=mod;
					else{
						if(s[x-1]=='1')dp[i][k]+=dp[i^(1<<j)][k],dp[i][k]%=mod;
						else dp[i][k+1]+=dp[i^(1<<j)][k],dp[i][k+1]%=mod;
					}
				}
			}
		}int ans=0;
		for(int i=0;i<=n-m;i++){
			ans+=dp[(1<<n)-1][i];
			ans%=mod;
		}cout<<ans;
		return 0;
	}cout<<0;
	return 0;
}
