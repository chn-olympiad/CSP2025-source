#include<bits/stdc++.h>
using namespace std;
#define int long long
#define psb push_back
const int N=2e6+10,p=998244353;
int n,m,ans=1,a[N],dp[N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i],ans=ans*2%p;
	sort(a+1,a+n+1),m=a[n];
	dp[0]=1;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=a[i];++j) ans-=dp[j];
		for(int j=m;j>=a[i];--j) dp[j]=(dp[j]+dp[j-a[i]])%p;
		ans%=p;
	}
	cout<<(ans-1+p)%p;
	return 0;
}
