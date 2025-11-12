#include<bits/stdc++.h>
using namespace std;
#define int long long
#define psb push_back
const int N=3e5+10,md=998244353;
int n,m,ans,a[N],dp[20][N];
char c[N];
int f(int x){
	int ans=0;
	while(x) ans+=x&1,x>>=1;
	return ans;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>c[i];
	for(int i=0;i<m;++i) cin>>a[i];
	dp[0][0]=1;
	for(int i=1;i<1<<n;++i){
		int p=f(i);
		for(int j=0;j<n;++j) if((i>>j)&1)
			for(int k=0;k<p;++k){
//				cout<<i<<' '<<j<<' '<<k<<' '<<k+(c[p]=='1'&&k<a[j])<<'\n';
				(dp[k+(c[p]=='1'&&k<a[j])][i]+=dp[k][i-(1<<j)])%=md;
//				cout<<k<<' '<<(i-(1<<j))<<dp[]<<'\n';
//				cout<<dp[k+(c[p]=='1'&&k<a[j])][i]<<'\n';
			}
	}
//	for(int i=0;i<=n;++i){
//		for(int j=0;j<1<<n;++j) cout<<dp[i][j]<<' ';
//		cout<<'\n';
//	}
	for(int i=m;i<=n;++i) ans+=dp[i][(1<<n)-1];
	cout<<ans%md;
	return 0;
}
