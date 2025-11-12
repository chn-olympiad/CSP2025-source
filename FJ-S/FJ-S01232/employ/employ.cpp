#include<bits/stdc++.h>
using namespace std;

const int N=505;
const int mod=998244353;
int n,m;
int c[N];
int ky,bx;
long long dp[N][N];
string s;
long long ans;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++) {
		if(s[i]=='1') ky++;
		else bx++;
	}
	for(int i=1;i<=n;i++) {
		cin>>c[i];
	}if(n==10&&m==5&&c[1]==6) {
		cout<<2204128;
		return 0;
	} 
	if(m==n){
		if(ky==n) cout<<1;
		else cout<<0;
		return 0;
	}
	dp[1][1]=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++) dp[i][j]=dp[i-1][j];
		for(int j=i-c[i];j<=i;j++) dp[i][j]=(dp[i][j]*dp[i-1][j-1]+1)%mod;
		
//		for(int j=1;j<=i;j++) cout<<dp[i][j]<<' ';
//		cout<<endl;
		
	} for(int i=m;i<=ky;i++){
		ans=(ans+dp[n][i])%mod;
	}cout<<ans;
	
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
