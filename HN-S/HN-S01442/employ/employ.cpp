#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e2+5,mod = 998244353;
int n,m,c[N],t[N],dp[1<<22][N],ans;
string s;
bool fp;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s;
	s = " "+s;
	for(int i = 1;i<=n;i++)cin >> c[i];
	fp = 1;
	for(int i = 1;i<=n;i++){
		if(s[i]=='0'||c[i]==0)fp = 0;
	}
	if(fp){
		ans = 1;
		for(int i = 1;i<=n;i++)ans = ans*i%mod;
		cout << ans;
		return 0;
	}
	if(m==n){
		for(int i = 1;i<=n;i++){
			if(s[i]=='0'||c[i]==0){
				cout << 0;
				return 0;
			}
		}
		ans = 1;
		for(int i = 1;i<=n;i++)ans = ans*i%mod;
		cout << ans;
		return 0;
	}
	for(int i = 1;i<=n;i++){
		if(c[i]!=0&&s[1]=='1')dp[(1LL<<(i-1))][0] = 1;
		else dp[(1LL<<(i-1))][1] = 1;
	}
	for(int i = 1;i<(1LL<<n);i++){
		int x = i,ct = 0;
		while(x){
			if(x%2)ct++;
			x/=2;
		}
		if(ct==1)continue;
		for(int j = 0;j<n;j++){
			for(int k = 0;k<n;k++){
				if(((1LL<<k)&i)==0)continue;
				int t = i-(1LL<<k);
				if(c[k+1]>j&&s[ct]=='1')dp[i][j] = (dp[i][j]+dp[t][j])%mod;
				if(s[ct]=='0'&&j>0)dp[i][j] = (dp[i][j]+dp[t][j-1])%mod;
				else if(c[k+1]<j&&j>0)dp[i][j] = (dp[i][j]+dp[t][j-1])%mod;
			}
		}
	}
	for(int i = 0;i<=n-m;i++){
		ans+=dp[(1LL<<n)-1][i];
		ans%=mod;
	}
	cout << ans;
	return 0;
}
