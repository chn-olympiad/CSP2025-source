#include <bits/stdc++.h>
#define ll long long
using namespace std; ll read() {ll x=0, f=1; char c=getchar();
while(c<48 || c>57) f=c=='-'?-1:1, c=getchar(); while(c>47 && c<58)
x=(x<<1)+(x<<3)+c-48, c=getchar(); return x*f;} void write(ll x)
{ll st[41], tp=0; if(x<0) putchar('-'), x=-x; do st[tp++]=x%10,
x/=10; while(x); while(tp) putchar(st[--tp]+48);} ll n,m,a[501],
p[501],bz[501],res,ans; char s[501]; const ll mod=998244353;

void dfs(ll x)
{
	if(x>n) {res=0; for(int i=1; i<x; ++i) res+=res>=a[p[i]] ||
	s[i-1]^49; if(n-res>=m) ans=(ans+1)%mod; return;} for(int i=1;
	i<=n; ++i) {if(!bz[i]) bz[i]=1, p[x]=i, dfs(x+1), bz[i]=0;}
}

int main()
{
	freopen("employ.in","r",stdin); freopen("employ.out","w",stdout);
	n=read(); m=read(); scanf("%s",s); for(int i=1; i<=n; ++i)
	a[i]=read(); dfs(1); write(ans); return 0;
}
