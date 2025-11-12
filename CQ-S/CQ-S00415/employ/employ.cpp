#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,p[15],tagA=1;
int dp[505][505];
string s;
int c[505];
int C[505][505];
void init(){
	C[0][0]=1;
	for(int i=1;i<505;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
}
signed main(){
     freopen("employ.in","r",stdin);
     freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin>>n>>m;
	cin>>s;
	init();
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(s[i]=='0') tagA=0;
		dp[i][0]=1;
	} 
	if(n<=10){
		for(int i=1;i<=n;i++) p[i]=i;
		int ans=0;
		do{
			int res=0;
			for(int i=1;i<=n;i++){
				if(s[i]=='0'||res>=c[p[i]]){
					res++;
				}
			}
			if(n-res>=m) ans=(ans+1)%mod;
		}while(next_permutation(p+1,p+n+1));
		cout<<ans<<"\n";
		return 0;
	}
	if(tagA){
		int res=1;
		for(int i=1;i<=n;i++){
			res=res*i%mod;
		}
		cout<<res<<"\n";
		return 0;
	}
	if(m==n){
		cout<<0<<"\n";
		return 0;
	}
	sort(c+1,c+n+1);
	dp[0][0]=1;
	for(int j=1;j<=n;j++){
		for(int k=1;k<=j;k++){
			for(int i=1;i<=n;i++){
				if(c[i]>(j-k)){
					if(s[j]=='1')dp[j][k]+=dp[j-1][k-1]*C[n][i]%mod;
				}
			}
			dp[j][k]+=dp[j-1][k]%mod;
			dp[j][k]%=mod;
		}
	}
	int ans=0;
	for(int i=m;i<=n;i++) ans=(ans+dp[n][i])%mod;
	cout<<ans<<"\n";
    return 0;
}
/*
3 2
101
1 1 2
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/

