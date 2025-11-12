#include<bits/stdc++.h>
using namespace std;
bool r[5005];
int n,a[5005];
long long ans;
void f(int s)
{
	ans%=998244353;
	if(s>n)
	return ;
	int c1[5005],c2[5005];
	for(int i=1;i<=s;i++)
	{
		r[i]=1;
	}
	for(int i=1;i<=n;i++)
		c1[i]=0;
	while(1)
	{
		int j=0;
		for(int i=1;i<=n;i++)
		{
			if(r[i]==1)
			{
				c1[j]=a[i];
				c2[j]=i;
				j++;
			}
		}
		int h=0;
		for(int i=1;i<=j-1;i++)
		{
			h+=c1[i];
		}
		if(h>2*c1[s])
		ans++;
		bool z=0;
		int v=0;
		for(int i=j-1;i>=1;i++)
		{
			if(c2[i]+1<=n)
			{
				for(int k=i;k<=i+v;k++)
				{
					c2[k]-=1;
				}
				c2[i]++;
				z=1;
				break;
			}
			else
			{
				v++;
			}
		}
		if(z==0)
		{
			break;
			f(s+1);
		}
	}
}
int main()
{
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	f(3);
	cout<<ans;
	return 0;
}
