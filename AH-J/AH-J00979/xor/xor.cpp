#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],x[500005],ans,cnt=1;
struct z
{
	int l,r;
}s[500005];
bool cmp(z x,z y)
{
	return (x.l+x.r+(x.r-x.l))<(y.l+y.r+(y.r-y.l));
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	bool f=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=1)
		{
			f=0;
			break;
		}
	}
	if(f)
	{
		if(k==1)
		{
			cout<<n;
			return 0;
		}
		if(k==0)
		{
			cout<<n/2;
			return 0;
		}
		cout<<0;
		return 0;
	}
	f=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=0)
		{
			f=0;
			break;
		}
	}
	if(f)
	{
		if(k==0)
		{
			cout<<n;
			return 0;
		}
		cout<<0;
		return 0;
	}
	x[1]=a[1];
	for(int i=2;i<=n;i++) x[i]=x[i-1]^a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if((x[j]^x[i-1])==k)
			{
				ans++;
				s[ans].l=i;
				s[ans].r=j;
			}
		}
	}
	if(ans==0)
	{
		cout<<0;
		return 0;
	}
	sort(s+1,s+ans+1,cmp);
	int p=s[1].r;
	for(int i=2;i<=ans;i++)
	{
		if(s[i].l>p)
		{
			p=max(p,s[i].r);
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
