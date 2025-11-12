#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct AA{
	int a,b,c;
	bool tag;
	inline bool operator<(const AA z) const {
		return a-b>z.a-z.b;
	}
}a[N];
long long dp[N];
void solve(){
	int n;
	long long ans=0;
	cin>>n;
	for(int i=0;i<=(n>>1);i++) dp[i]=0;
	for(int i=1;i<=n;i++)
		cin>>a[i].a>>a[i].b>>a[i].c;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=(n>>1);j>=1;j--)
			if(a[i].a>=a[i].b){
				if(i-j<=(n>>1)) dp[j]=max(dp[j]+a[i].a,dp[j-1]+a[i].c);
				else 			dp[j]=max(dp[j]+a[i].b,dp[j-1]+a[i].c);
			}
			else{
				if(n-i<(n>>1))  dp[j]=max(dp[j]+a[i].b,dp[j-1]+a[i].c);
				else			dp[j]=max(dp[j]+a[i].a,dp[j-1]+a[i].c);
			}
		if(i<=(n>>1)) dp[0]+=a[i].a;
		else dp[0]+=a[i].b;
	}
	for(int i=0;i<=(n>>1);i++) ans=max(ans,dp[i]);
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	for(cin>>T;T--;) solve();
	return 0;
}
