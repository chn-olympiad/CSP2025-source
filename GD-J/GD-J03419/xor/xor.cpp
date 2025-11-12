#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],num1,num0;
bool flag;
long long yh(long long shu,long long xin)
{
	string u="",v="",fin="";
	while (shu>0)
	{
		u=char(shu%2+'0')+u;
		shu/=2;
	}
	while (xin>0)
	{
		v=char(xin%2+'0')+v;
		xin/=2;
	}
	while (true)
	{
		if (u.size()<v.size())
		{
			u='0'+u;
		}else if (u.size()>v.size())
		{
			v='0'+v;
		}else
		{
			break;
		}
	}
	long long len=u.size();
	for (long long i=0;i<=len-1;i++)
	{
		if (u[i]!=v[i])
		{
			fin=fin+'1';
		}else
		{
			fin=fin+'0';
		}
	}
	long long hh=0;
	for (long long i=0,j=len-1;i<=len-1,j>=0;i++,j--)
	{
		if (fin[j]=='1')
		{
			hh+=pow(2,i);
		}
	}
	return hh;
}
int main()
{
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if (a[i]==1)
		{
			num1++;
		}else if (a[i]==0)
		{
			num0++;
		}else
		{
			flag=true;
		}
	}
	if (k==1 && !flag)
	{
		cout<<num1;
		return 0;
	}else if (k==0 && !flag)
	{
		cout<<num0+num1/2;
		return 0; 
	}
	long long ans=0;
	long long shu=a[1];
	for (long long i=1;i<=n;i++)
	{
		if (shu==k || a[i]==k)
		{
			ans++;
			shu=a[i+1];
		}else
		{
			shu=yh(shu,a[i+1]);
		}
	}
	cout<<ans;
	return 0;
}
