#include <bits/stdc++.h>
#define ll long long
using namespace std; int read() {int x=0, f=1; char c=getchar();
while(c<48 || c>57) c=getchar(), f=c=='-'?-1:1; while(c>47 && c<58)
x=(x<<1)+(x<<3)+c-48, c=getchar(); return x*f;} void write(int x)
{int st[41], tp=0; if(x<0) putchar('-'), x=-x; do st[tp++]=x%10,
x/=10; while(x); while(tp) putchar(st[--tp]+48);} int n,a[5001],mx;
ll f[5001]={1},inv[5001]={1},ans; const int mod=998244353; int qpow(ll x)
{int y=mod-2; ll res=1; while(y) {if(y&1) res=res*x%mod; x=x*x%mod; y>>=1;}
return res;} int c(int n, int m) {return f[n]*inv[m]%mod*inv[n-m]%mod;}
void dfs(int x, int y, int z, int p) {if(x>n) {if(p>2 && y>z<<1)
ans=(ans+1)%mod; return;} dfs(x+1,y,z,p); dfs(x+1,y+a[x],max(z,a[x]),p+1);}

int main()
{
	freopen("polygon.in","r",stdin); freopen("polygon.out","w",stdout);
	n=read(); for(int i=1; i<=n; ++i) a[i]=read(), mx=max(mx,a[i]); if(mx<2)
	{for(int i=1; i<=n; ++i) f[i]=f[i-1]*i%mod; inv[n]=qpow(f[n]);
	for(int i=n-1; i; --i) inv[i]=inv[i+1]*(i+1)%mod; for(int i=3; i<=n; ++i)
	ans=(ans+c(n,i))%mod;} else dfs(1,0,0,0); write(ans); return 0;
}
