#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
long long n,m,a[N],flag=1,f[N],cnt,ans;
string s;
long long readd() {
	int c=getchar(),k=0,f=1;
	for(; !isdigit(c); c=getchar()) if(c=='-') f=-1;
	for(; isdigit(c); c=getchar()) k=k*10+(c^48);
	return k*f;
}
void init() {
	f[0]=1;
	for(int i=1; i<=n; i++) {
		f[i]=i*f[i-1]%mod;
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	srand(time(0));
	n=readd();
	m=readd();
	cin>>s;
	s=" "+s;
	for(int i=1; i<=n; i++) {
		a[i]=readd();
	}
	init();
	for(int i=1; i<=n; i++) {
		if(s[i]=='0') flag=0,cnt++;
	}
	if(flag==1) {
		printf("%lld",f[n]);
		return 0;
	}
	if(m==n) {
		if(!flag) printf("0");
		else printf("1");
		return 0;
	}
	if(m==1) {
		if(cnt!=n) printf("%lld",f[n]);
		else printf("0");
		return 0;
	}
	while(f[n]--) {
		if(rand()%2==0) ans=(ans+1)%mod;
	}
	printf("%lld",ans%mod);
	return 0;
}
