#include<bits/stdc++.h>
using namespace std;
int sum[500005];
struct node
{
	int l,r;
}a[500005];
bool cmp(node a,node b)
{
	return a.r<b.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0,ans=0,r=0,t;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		sum[i]=sum[i-1]^t;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if((sum[i]^sum[j-1])==k)
			{
				a[++cnt].l=j;
				a[cnt].r=i;
			}
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		if(a[i].l>r)
		{
			r=a[i].r;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
