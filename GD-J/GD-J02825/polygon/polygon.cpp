#include <bits/stdc++.h>
using namespace std;
#define For(i,x,y) for(int i=x;i<=y;i++)
#define ll long long
const int M=5101;
const int inf=998244353;
int n,a[M];
ll dp[3][M*M],s[M],ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) s[i]=s[i-1]+a[i];
	sort(a+1,a+1+n);
	For(i,0,2) dp[i][0]=1;
	For(i,1,n-1){
		For(j,1,s[i]){
			dp[i%3][j]=(dp[(i-1)%3][j]+dp[(i-1)%3][j-a[i]])%inf;
		}
		For(j,a[i+1]+1,s[i]) ans=(ans+dp[i%3][j])%inf;
	}
	printf("%lld",ans);
	return 0;
}
