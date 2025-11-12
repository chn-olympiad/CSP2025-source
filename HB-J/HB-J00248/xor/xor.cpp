#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s[500005],h,ans,cnt;
struct node
{
	int l,r;
}q[500005];
bool cmp(node x,node y)
{
	return x.r<y.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
			h=1;
		s[i]=a[i]^s[i-1];
	}
	if(k==0 && h==0)
	{
		cout<<n/2;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int x=s[j]^s[i-1];
			if(x==k)
			{
				q[++cnt]={i,j};
			}
		}
	}
	sort(q+1,q+1+cnt,cmp);
	int ls=0;
	for(int i=1;i<=cnt;i++)
	{
		if(q[i].l>ls)
		{
			ls=q[i].r;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
