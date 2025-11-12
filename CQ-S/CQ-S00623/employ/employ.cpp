#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 505;
const int N = 18;
const ll mod = 998244353;
int n,m,k,c[M],ans;
string st;
ll dp[N][1<<N];
bool fl1,fl2;
void solve1(){//n<=18
	dp[0][0]=1;
	for(int s=0;s<(1<<n);s++){
		int r=0;
		for(int i=0;i<n;i++)if(s>>i&1)r++;
		for(int j=0;j<=r;j++){
			for(int i=0;i<n;i++)if(!(s>>i&1)){
				int t=s|(1<<i);
				if(st[r]=='0'||r-j>=c[i+1])dp[j][t]=(dp[j][t]+dp[j][s])%mod;
				else dp[j+1][t]=(dp[j+1][t]+dp[j][s])%mod;
			}
		}
	}
	for(int i=m;i<=n;i++){
		ans=(ans+dp[i][(1<<n)-1])%mod;
	}
	cout<<ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>st;
	for(int i=0;i<n;i++)if(st[i]=='0')fl1=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=18){
		solve1();
	}else if(!fl1){
		cout<<0;
	}else if(n==m){
		ans=1;
		for(int i=0;i<n;i++){
			ans=ans*(i+1)%mod;
			if(st[i]=='1'){
				cout<<0;
				return 0;
			}
			if(c[i+1]==0){
				cout<<0;
				return 0;
			}
		}
		cout<<ans;
	}
}
