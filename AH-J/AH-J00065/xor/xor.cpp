#include <bits/stdc++.h>//#Shang4Shan
using namespace std;
typedef long long ll;
struct tree
{
	ll xors,l,r;
}t[2000006];
ll n,k,a[500005],maxx,cnt;
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
struct anns
{
	ll l,r,len;
}xl[500005];
bool cmp(anns a,anns b)
{
	if (a.l<b.l) return 1;
	else return 0;
}
inline void build(ll p,ll l,ll r)
{
	t[p].l=l;
	t[p].r=r;
	if (l==r)
	{
		t[p].xors=a[l];
		return;
	}
	ll mid=(l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	t[p].xors=t[p*2].xors^t[p*2+1].xors;
	/*if (t[p].xors==k)
	{
		xl[++cnt].l=l;
		xl[cnt].r=r;
		xl[cnt].len=r-l+1;
	}*/
}
/*inline void dfs(ll p)
{
	cout<<p<<' '<<t[p].l<<' '<<t[p].r<<' '<<t[p].xors<<endl;
	if (t[p].l==t[p].r) return;
	dfs(p*2);
	dfs(p*2+1);
}*/
inline ll ask(ll p,ll x,ll y)
{
	//cout<<p<<' '<<t[p].l<<' '<<t[p].r<<' '<<x<<' '<<y<<"      ";
	if (x<=t[p].l&&t[p].r<=y)
	{
		//cout<<"R"<<p<<' '<<t[p].xors<<endl;
		return t[p].xors;
	}
	ll mid=(t[p].l+t[p].r)/2;
	ll ans=-1;
	if (x<=mid) ans=ask(p*2,x,y);
	if (y>mid) 
	{
		if (ans!=-1)
		ans=ans^ask(p*2+1,x,y);
		else ans=ask(p*2+1,x,y);
	}
	//cout<<p<<' '<<t[p].l<<' '<<t[p].r<<' '<<x<<' '<<y<<' '<<ans<<endl;
	return ans;
}
ll dp[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();
	k=read();
	for (ll i=1;i<=n;i++)
	a[i]=read();
	build(1,1,n);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (ask(1,i,j)==k) 
			{
				xl[++cnt].l=i;
		        xl[cnt].r=j;
		        xl[cnt].len=j-i+1;
			}
		}
	}
	//sort(xl+1,xl+1+cnt,cmp);
	//cout<<ask(1,1,1);
	//<<xl[1].len<<' '<<xl[2].len;
	for (int i=1;i<=cnt;i++)
	{
		for (int j=n;j>=xl[i].len;j--)
		dp[j]=max(dp[j],dp[j-xl[i].len]+1);
	}
	cout<<dp[n];
	return 0;
}
