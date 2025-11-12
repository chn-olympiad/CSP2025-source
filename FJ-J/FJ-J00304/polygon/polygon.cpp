#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,a[1000005],maxx,dp[5005][10005],ans,p[100005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	p[0]=1;
	for(int i=1;i<=5000;i++) p[i]=(p[i-1]*2)%mod;
	for(int i=1;i<=n;i++){
	    cin>>a[i];
	    maxx=max(maxx,a[i]);
    }
	sort(a+1,a+n+1);
	for(int i=0;i<maxx;i++) dp[0][i]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=maxx;j++) dp[i][j]=p[i];
		dp[i][maxx]=(dp[i][maxx]-1+mod)%mod;
		for(int j=maxx+1;j<=2*maxx;j++){
		dp[i][j]=(dp[i-1][j]+dp[i-1][j-a[i]])%mod;
	    }
		ans=(ans+dp[i-1][maxx+a[i]])%mod;
	}
	cout<<ans;
}
