#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
#define pa pair<int,int>
#define mkp make_pair
#define FI first
#define SE second
int n,m,c[505],num[505],dp[1<<18][18],ans,zer,qz[505];
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)num[i]=s[i-1]-'0';
	for(int i=1;i<=n;i++){
		cin>>c[i];
		qz[c[i]]++;
	}
	for(int i=0;i<=n;i++)qz[i]=qz[i-1]+qz[i];
	if(m==1){
		ans=1;
		for(int i=1;i<=n;i++){
			if(num[i]==0)zer++;
			else ans=ans*(qz[i-1]-(i-1-zer))%mod;
		}
		for(int i=1;i<=zer;i++)ans=ans*i%mod;
		int res=1;
		for(int i=1;i<=n;i++)res=res*i%mod;
		cout<<(res-ans+mod)%mod;
		return 0;
	}
	dp[0][0]=1;
	for(int i=0,cnt;i<(1<<n);i++){
		cnt=0;
		for(int j=1;j<=n;j++){
			if(i&(1<<j-1))cnt++;
		}
		for(int p=0;p<=n;p++){
			for(int j=1;j<=n;j++){
				if(i&(1<<j-1))continue;
				if(c[j]<=p||num[cnt+1]==0){
					dp[i|(1<<j-1)][p+1]=(dp[i|(1<<j-1)][p+1]+dp[i][p])%mod;
//					cout<<i<<' '<<j<<' '<<p<<' '<<cnt<<'\n';
				}else{
					dp[i|(1<<j-1)][p]=(dp[i|(1<<j-1)][p]+dp[i][p])%mod;
				}	
			}
		}
	}
	for(int i=0;i<=n-m;i++){
		ans=(ans+dp[(1<<n)-1][i])%mod;
	}
	cout<<ans;
	return 0;
}


