#include <bits/stdc++.h>
#define ll int
using namespace std; ll read() {ll x=0, f=1; char c=getchar();
while(c<48 || c>57) c=getchar(), f=c=='-'?-1:1; while(c>47 && c<58)
x=(x<<1)+(x<<3)+c-48, c=getchar(); return x*f;} void write(ll x)
{ll st[41], tp=0; if(x<0) putchar('-'), x=-x; do st[tp++]=x%10,
x/=10; while(x); while(tp) putchar(st[--tp]+48);} ll n,k,cnt,a[500001],
sum[500001],lst[500001],f[500001],g[500001],res[500001],l,r,mid;
struct node {ll l,r;} p[500001]; bool cmp(node x, node y) {return x.r<y.r;}

ll main()
{
	freopen("xor.in","r",stdin); freopen("xor.out","w",stdout);
	n=read(); k=read(); for(ll i=1; i<=n; ++i) {a[i]=read();
	sum[i]=sum[i-1]^a[i]; if(sum[i]==k) f[i]=1; if(lst[sum[i]^k])
	f[i]=lst[sum[i]^k]+1; lst[sum[i]]=i;} for(ll i=1; i<=n; ++i)
	{if(f[i]) p[++cnt]={f[i],i};} sort(p+1,p+cnt+1,cmp);
	for(ll i=1; i<=cnt; ++i) {l=0; r=i; while(l<r-1) {mid=l+r>>1;
	if(p[mid].r<p[i].l) l=mid; else r=mid;} g[i]=res[l]+1;
	res[i]=max(res[i-1],g[i]);} write(res[cnt]); return 0;
}
