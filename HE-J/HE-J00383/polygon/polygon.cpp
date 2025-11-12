#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,mod=998244353;
int n,a[N];
long long dp[N<<1];
long long pw[N],s[N<<1];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	pw[0]=1;
	for (int i=1;i<=n;i++)
		pw[i]=(pw[i-1]<<1)%mod;
	int mxx=0;
	for (int i=1;i<=n;i++) mxx=max(mxx,a[i]);mxx<<=1;
	long long cnt=0;
	for (int i=1;i<=n;i++){
		for (int k=a[i];k<=mxx;k++)
			dp[k]=(1+s[k-a[i]])%mod;
		for (int k=a[i];k<=mxx;k++)
			s[k]=(s[k]+dp[k])%mod;
		cnt=(cnt+dp[a[i]<<1])%mod;
	}
	cout<<((pw[n]-cnt-1)%mod+mod)%mod;
	return 0;
}
