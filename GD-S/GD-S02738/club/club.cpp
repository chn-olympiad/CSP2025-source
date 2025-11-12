#include <bits/stdc++.h>
#define ll int
#define endl putchar(10)
using namespace std; ll read() {ll x=0, f=1; char c=getchar();
while(c<48 || c>57) f=c=='-'?-1:1, c=getchar(); while(c>47 && c<58)
x=(x<<1)+(x<<3)+c-48, c=getchar(); return x*f;} void write(ll x)
{ll st[41], tp=0; if(x<0) putchar('-'), x=-x; do st[tp++]=x%10,
x/=10; while(x); while(tp) putchar(st[--tp]+48);}
ll t,n,f[2][201][201],x,y,p[100001],ans; struct node {ll x,y,z;}
a[100001]; bool cmp(node x, node y) {return x.x>y.x;}

ll main()
{
	freopen("club.in","r",stdin); freopen("club.out","w",stdout);
	t=read();
	
	while(t--)
	{
		n=read(); ans=0; x=1; y=1; for(ll i=1; i<=n; ++i)
		a[i]={read(),read(),read()}, x=a[i].y?0:x, y=a[i].z?0:y;
		f[0][0][0]=0; if(x&y) {sort(a+1,a+n+1,cmp); for(ll i=1;
		i<=n>>1; ++i) ans+=a[i].x; write(ans); endl; continue;}

		for(ll i=1; i<=n; ++i)
		{
			for(ll j=0; j<=min(n>>1,i); ++j) {for(int k=max
			(i-j-(n>>1),0); k<=min(n>>1,i-j); ++k) f[i&1][j][k]=0;}
			
			for(ll j=0; j<=min(n>>1,i); ++j)
			{
				for(ll k=max(i-j-(n>>1),0); k<=min(n>>1,i-j); ++k)
				{
					if(j) f[i&1][j][k]=f[i&1^1][j-1][k]+a[i].x;
					if(k) f[i&1][j][k]=max(f[i&1][j][k],f[i&1^1]
					[j][k-1]+a[i].y); if(i-j-k) f[i&1][j][k]=
					max(f[i&1][j][k],f[i&1^1][j][k]+a[i].z);
				}
			}
		}

		for(ll i=0; i<=n>>1; ++i) {for(int j=(n>>1)-i; j<=min(n>>1,
		n-i); ++j) ans=max(ans,f[n&1][i][j]);} write(ans); endl;
	}
	
	return 0;
}
