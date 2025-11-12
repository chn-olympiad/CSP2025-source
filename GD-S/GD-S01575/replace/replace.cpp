#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
const ll MAXN=1e6+5;
const ll inf=LONG_LONG_MAX;
ll b[MAXN],c[MAXN],cnt,c26[MAXN];
struct node
{
	ll a,b,l;
}a[MAXN];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll n,m;
	cin>>n>>m;
	c26[0]=1;
	for(register int i=1;i<=1e6;i++)
	{
		c26[i]=c26[i-1]*26%MOD;
	}
	for(register int i=1;i<=n;i++)
	{
		string q,w;
		cin>>q>>w;
		if(q!=w)
		{
			cnt++;
			a[cnt].l=q.size();
			for(register int i=0;i<q.size();i++)
			{
				a[cnt].a=(a[cnt].a+(q[i]-'a')*c26[i]%MOD)%MOD;
				a[cnt].b=(a[cnt].b+(w[i]-'a')*c26[i]%MOD)%MOD;
			}
		}
	}
	while(m--)
	{
		string q,w;
		ll z=-inf,x=inf,ans=0;
		cin>>q>>w;
		for(register int i=1;i<=q.size();i++)
		{
			if(q[i-1]!=w[i-1])
			{
				x=min(x,i*1ll);
				z=max(z,i*1ll);
			}
			b[i]=(b[i-1]+(q[i-1]-'a')*c26[i-1]%MOD)%MOD;
			c[i]=(c[i-1]+(w[i-1]-'a')*c26[i-1]%MOD)%MOD;
		}
		for(register int i=1;i<=cnt;i++)
		{
			for(register int j=max(a[i].l,z);j<=min(x+a[i].l-1,(ll)q.size());j++)
			{
				if((b[j]-b[j-a[i].l]+MOD)%MOD==a[i].a*c26[j-a[i].l]%MOD)
				{
					if((c[j]-c[j-a[i].l]+MOD)%MOD==a[i].b*c26[j-a[i].l]%MOD)
					{
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
