#include<bits/stdc++.h>
using namespace std;
long long num[1001001];
long long n,k;
long long ans;
int minn=1e9;
int maxn;
int f(int l,int r,int o)
{
	if(maxn>=n&&minn<=1)
		return ans;
	int x;
	x=l;
	int res=-1;
	int temp=o;
	while(x<=r&&res!=k)
	{
		if(x==l)
			res=num[l];
		else
			res=res^num[x];
		x++;
		temp++;
	}
	minn=min(minn,l);
	maxn=max(maxn,x-1);
	if(res==k)
	{
		ans++;
	}
	while(maxn<n)
	{
		f(x,n,o);
	}
	while(minn>1)
	{
		f(1,l-1,o);
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int flag=0;
	int flag1=0;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
		if(num[i]!=1)
			flag=1;
		if(num[i]!=k)
			flag1=1;
	}
	if(k==0&&flag==0)
	{
		cout<<n/2;
	}
	if(flag1==0)
        cout<<n;
	else
	{
		int max_n=0;
		long long temp=-1;
		for(int i=1;i<=n;i++)
		{
			maxn=i;
			minn=i;
			ans=0;
			f(i,n,i);
			int oi=ans;
			if(oi>max_n)
				max_n=ans;
		}

		cout<<max_n;
	}
	return 0;
}
