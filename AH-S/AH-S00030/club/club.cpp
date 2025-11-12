#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read()
{
    char ch;
    ll s=0,f=1;
    ch=getchar();
    while (ch<'0'||ch>'9')
    {
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9')
    {
        s=s*10+(ch-'0');
        ch=getchar();
    }
    return s*f;
}
ll t,n,ans,ni;
ll a1[100005],a2[100005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    t=read();
    for (ll k=1;k<=t;k++)
    {
		memset (a1,0,sizeof(a1));
		n=read();
		ni=(n/2);
		for (ll i=1;i<=n;i++)
		{
			ll x;
			x=read();
			a1[i]=x;
			x=read();
			a2[i]=x;
			x=read();
		}
		sort(a1+1,a1+1+n);
		for (ll i=n;n-i+1<=ni;i--)
		{
			ans+=a1[i];
		}
		
	}
	cout<<ans;
    return 0;
}
