#include<bits/stdc++.h>
#define N 5002
#define int long long
using namespace std;
int s,f;
char ch;
inline int read() {
	s=0,f=1;
	do if(ch=='-') f=-1;
	while((ch=getchar())<48);
	do s=(s<<3)+(s<<1)+(ch^48);
	while((ch=getchar())>47);
	return s*f;
}
inline void write(int x) {
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+48);
}
int n,a[N],dp[N],ans,sum,mul;
const int mod=998244353;
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1; i<=n; i++) a[i]=read();
	sort(a+1,a+n+1);
	dp[0]++;
	dp[a[1]]++;
	dp[a[2]]++;
	dp[a[1]+a[2]]++;
	mul=2;
	for(int i=3; i<=n; i++){
		mul=(mul*2)%mod;
		ans=(ans+mul)%mod;
		for(int j=0; j<=a[i]; j++) ans=(ans-dp[j]+mod)%mod;
		for(int k=a[n]; k>=a[i]; k--) dp[k]=(dp[k]+dp[k-a[i]])%mod;
	}
	write(ans%mod);
	return 0;
}
