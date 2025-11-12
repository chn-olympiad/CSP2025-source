#include<bits/stdc++.h>
using namespace std;
int n,k,b,a[500005],p[500005],f[500005],cnt,ok,ans,c_0,c_1,cc;
struct node
{
	int l,r,m;
}c[500005];
bool cmp(node x,node y)
{
	if(x.m==y.m)
	{
		if(x.l==y.l)
		{
			return x.r<y.r;
		}
		return x.l<y.l;
	}
	return x.m<y.m;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		p[i]=p[i-1]^a[i];
		if(a[i]==0)
		{
			c_0++;
		}
		else if(a[i]==1)
		{
			c_1++;
		}
	}
	if(c_1==n&&k==0)
	{
		cout<<n/2;
		return 0;
	}
	if(c_1+c_0==n&&k==0)
	{
		if(a[1]==0)
		{
			ans++;
		}
		for(int i=2;i<=n;i++)
		{
			if(a[i]==0)
			{
				ans++;
			}
			if(a[i-1]==1&&a[i]==1)
			{
				if(cc)
				{
					cc=0;
					continue;
				}
				ans++;
				cc=1;
			}
		}
		cout<<ans;
		return 0;
	}
	if(c_1+c_0==n&&k==1)
	{
		cout<<c_1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			b=p[j]^p[i-1];
			if(b==k)
			{
				cnt++;
				c[cnt].l=i,c[cnt].r=j;
				c[cnt].m=j-i+1;
			}
		}
	}
	sort(c+1,c+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		ok=0;
		for(int j=c[i].l;j<=c[i].r;j++)
		{
			if(f[j])
			{
				ok=1;
				break;
			}
		}
		if(ok==0)
		{
			ans++;
			for(int j=c[i].l;j<=c[i].r;j++)
			{
				f[j]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
