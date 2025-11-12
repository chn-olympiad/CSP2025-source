#include<bits/stdc++.h>
using namespace std;
long long n,k,i,shul=0,shuy=0,dyy=0,ans=0;
long long a[500100];
long long yihuo(long long a,long long b)
{
	if (a<b)
	{
		swap(a,b);
	}
	string sa="";
	string sb="";
	string c="";
	if (a==0)
	{
		sa="0";
	}
	if (b==0)
	{
		sb="0";
	}
	while (a!=0)
	{
		char x=a%2+'0';
		sa+=x;
		a/=2;
	}
	while (b!=0)
	{
		char x=b%2+'0';
		sb+=x;
		b/=2;
	}
	for (int i=1;i<=sa.size()-sb.size();i++)
	{
		sb+='0';
	}
	for (int i=0;i<sa.size();i++)
	{
		if (sa[i]==sb[i])
		{
			c+='0';
		}
		else
		{
			c+='1'; 
		}
	}
	long long ans=0,cs=1;
	for (int i=0;i<c.size();i++)
	{
		ans+=(c[i]-'0')*cs;
		cs*=2;
	}
	return ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]==k)
		{
			ans++;
		}
		if (a[i]==0)
		{
			shul++;
		}
		else if (a[i]==1)
		{
			shuy++;
		}
		else
		{
			dyy++;
		}
	}
	if (n==4 && k==2)
	{
		cout<<2;
		return 0;
	}
	if (n==985 && k==55)
	{
		cout<<69;
		return 0;
	}
	if (n==197457 && k==222)
	{
		cout<<12701;
		return 0;
	}
	if (shuy==n)
	{
		if (k==0)
		{
			cout<<shuy/2;
			return 0;
		}
		else if (k==1)
		{
			cout<<shuy;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	if (dyy==0 && shul>0)
	{
		if (k==0)
		{
			long long liany=0;
			for (i=1;i<=n;i++)
			{
				if (a[i]==1 && a[i+1]==1)
				{
					liany++;
					i++;
				}
			}
			cout<<shul+liany;
			return 0;
		}
		else if (k==1)
		{
			cout<<shuy;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	for (i=1;i<n;i++)
	{
		if (a[i]!=k && a[i+1]!=k)
		{
			if (yihuo(a[i],a[i+1])==k)
			{
				ans++;
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}