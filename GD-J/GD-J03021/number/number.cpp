#include <bits/stdc++.h>
#define ll int
using namespace std; void write(ll x) {ll st[41], tp=0; if(x<0)
putchar('-'), x=-x; do st[tp++]=x%10, x/=10; while(x); while(tp)
putchar(st[--tp]+48);} ll n,cnt,a[1000001]; char s[1000001];

ll main()
{
	freopen("number.in","r",stdin); freopen("number.out","w",stdout);
	scanf("%s",s); n=strlen(s); for(ll i=0; i<n; ++i)
	{if(s[i]>47 && s[i]<58) a[++cnt]=s[i]-48;} sort(a+1,a+cnt+1);
	for(ll i=cnt; i; --i) write(a[i]); return 0;
}
