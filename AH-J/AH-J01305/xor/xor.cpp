#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005],f,ff,cnt,ans;
int sum[100005];
struct node
{
	int l,r;
}b[100005];
bool cmp(node a,node b)
{
	return a.r<b.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		if(a[i]!=1)
		{
			f=1;
		}
		if(a[i]!=1&&a[i]!=0)
		{
			ff=1;
		}
	}
	if(k==0&&!f)
	{
		cout<<n/2;
		return 0;
	}
	if((k==1||k==0)&&!ff)
	{
		int cnt,ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1) cnt++;
			if(cnt%2==k)
			{
				ans++;
				cnt=0;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if((sum[i]^sum[j-1])==k)
			{
				b[++cnt].l=j,b[cnt].r=i;
			}
		}
	}
	sort(b+1,b+cnt+1,cmp);
	int ed=INT_MIN;
	for(int i=1;i<=cnt;i++)
	{
		if(b[i].l>ed)
		{
			ans++;
			ed=b[i].r;
		}
	}
	cout<<ans;
	return 0;
}
