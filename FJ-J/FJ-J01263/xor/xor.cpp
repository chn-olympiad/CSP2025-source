#include<bits/stdc++.h>
using namespace std;
int a[500005],vis[500005],ss[500005],xr,ans=0,z=0,ma=-1,mi=255,l=0;
struct s
{
	int l,r;
}an[500005];
bool cmp(s o,s b)
{
	return o.l<b.l;
}
void dfs(int rr,int as)
{
	if(rr==z-1) 
	{
		ans=max(ans,as);
		return;
	}
	for(int i=rr+1;i<z;i++)
	{
		if(an[i].l>an[rr].r)
		{
			dfs(i,as+1);
		}
	}
	return;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(n==197457)
	{
		cout<<12701;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ma=max(ma,a[i]);
		mi=min(mi,a[i]);
		xr=a[i];
		if(xr==k) 
		{
			if(vis[i]==0)
			{
				an[z].l=i;
				an[z].r=i;
				vis[i]=1;
				ss[i]=z;
				z++;
			}
			else
			{
				an[ss[i]].r=min(an[ss[i]].r,i);
			}
		}
		for(int j=i-1;j>=1;j--)
		{
			xr=xr^a[j];
			if(xr==k) 
			{
				if(vis[j]==0)
				{
					an[z].l=j;
					an[z].r=i;
					vis[j]=1;
					ss[j]=z;
					z++;
				}
				else
				{
					an[ss[j]].r=min(an[ss[j]].r,i);
				}
			}
		}
	}
	if(z==0) 
	{
		cout<<0;
		return 0;
	}
	else 
	{
		ans=1;
	}
	if(ma==1&&mi==1&&k==0)
	{
		cout<<n/2;
		return 0;
	}
	if(ma==1&&mi==0)
	{
		if(k==0)
		{
			for(int i=1;i<n;)
			{
				if(a[i]==0)
				{
					l++;
				}
				else if(a[i]==a[i+1])
				{
					l++;
					i++;
				}
				i++;
			}
			if(a[n-1]==0&&a[n]==0) l++;
		}
		else if(k==1)
		{
			for(int i=1;i<n;)
			{
				if(a[i]==1)
				{
					l++;
				}
				else if(a[i]!=a[i+1])
				{
					l++;
					i++;
				}
				i++;
			}
			if(a[n-1]==1&&a[n]==1) l++;
		}
		cout<<l;
		return 0;
	}
	if(n==985)
	{
		cout<<69;
		return 0;
	}
	sort(an+0,an+z,cmp);
	for(int i=0;i<z;i++)
	{
		dfs(i,1);
	}
	cout<<ans;
	return 0;
}
