#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],b[500005],c[500005],ans,l,maxx=0;
long long yh(long long x,long long y)
{
	string a,b,c;
	long long ans2,ans3=0,z;
	while(x)
	{
		z=x%2;
		a=char(z+'0')+a;
		x/=2;
	}
	while(y)
	{
		z=y%2;
		b=char(z+'0')+b;
		y/=2;
	}
	if(a.size()>b.size())while(a.size()!=b.size())b="0"+b;
	else while(a.size()!=b.size())a="0"+a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]!=b[i])c=c+"1";
		else c=c+"0";
	}
	for(int i=c.size()-1,j=0;i>=0;i--,j++)
	{
		int p=j;
		ans2=1;
		while(p)
		{
			ans2*=2;
			p--;
		}
		ans3+=ans2*int(c[i]-'0');
	}
	return ans3;
}
int main()
{
	freopen("xor.in","w",stdin);
	freopen("xor.out","s",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		ans=a[i];
		if(ans==k)
		{
			b[++l]=i;
			c[l]=i;
			continue;
		}
		for(int j=i+1;j<=n;j++)
		{
			ans=yh(ans,a[j]);
			if(ans==k)
			{
				b[++l]=i;
				c[l]=j;
				break;
			}
			if(yh(ans,j)>k)break;
		}
	}
	long long l2=l;
	ans=0;
	for(int i=1;i<=l2;i++)
	{
		if(b[i]<=ans)l--;
		else ans=c[i];
	}
	cout<<l;
	return 0;
}

