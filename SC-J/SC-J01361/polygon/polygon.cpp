#include<algorithm>
using namespace std;
#define ll long long
#define mod 998244353
int d[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n,ans=0;
	cin>>n;
	vector<int>A(n);
	d[0]=1;for(int i=1;i<=5000;i++)d[i]=(d[i-1]*2)%mod;
	vector<vector<ll> >dp(10010,vector<ll>(n+1)),p(10010,vector<ll>(n+1)); 
	for(int i=0;i<n;i++)cin>>A[i];
	sort(A.begin(),A.end());
	for(int i=1;i<=2*A[n-1]+1;i++){
		for(int j=1;j<=n;j++){
			if(i<=A[j-1])dp[i][j]=d[j-1];
			else dp[i][j]=p[i-A[j-1]][j-1];
			p[i][j]=(dp[i][j]+p[i][j-1])%mod;
		}
	}
	for(int i=0;i<n;i++)ans=(ans+dp[2*A[i]+1][i+1])%mod;
	cout<<ans;
	return 0;
}