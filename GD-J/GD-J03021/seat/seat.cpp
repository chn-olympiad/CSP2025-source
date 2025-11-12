#include <bits/stdc++.h>
#define ll int
#define spc putchar(32)
using namespace std; ll read() {ll x=0, f=1; char c=getchar();
while(c<48 || c>57) c=getchar(), f=c=='-'?-1:1; while(c>47 && c<58)
x=(x<<1)+(x<<3)+c-48, c=getchar(); return x*f;}
void write(ll x) {ll st[41], tp=0; if(x<0) putchar('-'), x=-x;
do st[tp++]=x%10, x/=10; while(x); while(tp) putchar(st[--tp]+48);}
ll n,m,k,x=1,y=1,a[101]; bool cmp(ll x, ll y) {return x>y;}

ll main()
{
	freopen("seat.in","r",stdin); freopen("seat.out","w",stdout);
	n=read(); m=read(); for(ll i=1; i<=n*m; ++i) a[i]=read(); k=a[1];
	sort(a+1,a+n*m+1,cmp); for(ll i=1; i<=n*m; ++i) {if(a[i]==k)
	write(x), spc, write(y), exit(0); if(x&1 && y==n || x&1^1 && y<2)
	++x; else y+=x&1?1:-1;} return 0;
}
