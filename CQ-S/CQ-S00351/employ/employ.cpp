#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,x,y) for(register int i=x;i<=(int)y;++i)
#define rep1(i,x,y) for(register int i=x;i>=(int)y;--i)
#define pb push_back
#define fire signed
const int inf=1e18;
void in(int &x) {
	x=false;
	char c=getchar();
	int f=1;
	while(c>'9'||c<'0') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0') {
		x=x*10+c-'0';
		c=getchar();
	}
	x*=f;
}
int T=1;
const int N=5e2+10,M=19,mod=998244353;
int f[2][M][1<<M],p,q;
int n;
int c[N],m;
string s;
void solve() {
	in(n),in(m);
	cin>>s;
	s=" "+s;
	rep(i,1,n) in(c[i]);
	p=0,q=1;
	f[p][0][0]=1;
	rep(i,1,n) {
		rep(j,0,i-1) {
			rep(k,0,(1<<n)-1) {
				if(!f[p][j][k]) continue;
				rep(x,1,n) {
					if((k>>(x-1))&1) {
						continue;
					}
					if(s[i]=='0'||c[x]<=j) {
						f[q][j+1][(1<<(x-1))|(k)]=(f[q][j+1][(1<<(x-1))|k]+f[p][j][k])%mod;
					}else {
						f[q][j][(1<<(x-1))|k]=(f[q][j][(1<<(x-1))|k]+f[p][j][k])%mod;
					}
				}
			}
		}
		swap(p,q);
		rep(j,0,i-1) rep(k,0,(1<<n)-1) f[q][j][k]=0;
	}
	int res=0;
	rep(j,0,n-m) res=(res+f[p][j][(1<<n)-1])%mod;
	printf("%lld\n",res);
}
fire main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	while(T--) {
		solve();
	}
	return false;
}


