#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define debug(a) cout<<#a<<"="<<a<<"\n";
using namespace std;
const long long N=500+7,M=998244353;
long long n,m,b[N],dp[1<<18][N],ans;
char a[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	rep(i,1,n) cin>>b[i];
	if(n<=18){
		long long s=(1<<n)-1;
		dp[0][0]=1;
		rep(i,1,s){
			long long f=0;
			rep(j,1,n) if(i&(1<<(j-1))) f++;
			rep(j,0,f-1){
				rep(k,1,n){
					if(i&(1<<(k-1))){
						if(a[f]=='0') dp[i][j]=(dp[i][j]+dp[i-(1<<(k-1))][j])%M;
						else if(b[k]<=f-j-1) dp[i][j]=(dp[i][j]+dp[i-(1<<(k-1))][j])%M;
						else dp[i][j+1]=(dp[i][j+1]+dp[i-(1<<(k-1))][j])%M;
					}
				}	
			}
		}
		rep(i,m,n) ans=(ans+dp[s][i])%M;
		cout<<ans<<"\n";	
	}
	else{
		rep(i,1,n){
			if(a[i]=='0'){
				cout<<0<<"\n";
				return 0;
			}
		}
		long long s=0;
		rep(i,1,n) s+=(b[i]!=0);
		if(s<m){
			cout<<0<<"\n";
			return 0;
		}
		ans=1;
		rep(i,1,n){
			ans=ans*i%M;
		}
		cout<<ans<<"\n";
	}
    return 0;
}
