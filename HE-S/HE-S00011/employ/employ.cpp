#include <bits/stdc++.h>
using namespace std;
const long long M=998244353;
int n,m,c[505],l,r,x;
string s;
bool f=true;
int main()
{
	freopen("employ4.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for (int i=1;i<=n;i++)
	{
		cin>>c[i];
		if (c[i]==0) x++;
	}
	sort(c+1,c+n+1);
	for (int i=1;i<=n;i++)
	{
		if (s[i-1]=='1')
		{
			l++;
		}
		else
		{
			f=false;
		}
	}
	if (n-x<m) cout<<0;
	else if (l<m) cout<<0;
	else if (f)
	{
		long long sum=1;
		for (int i=1;i<=n-x;i++)
		{
			sum=sum*(1ll*i)%M;
		}
		cout<<sum;
	}
	else if (m==1)
	{
		long long ans=1,sum=0,num=0;
		for (int i=1;i<=n;i++)
		{
			if (s[i-1]=='0') r++;
			else
			{
				for (int j=1;j<=n;j++)
				{
					if (c[j]>r)
					{
						num=n-j+1;
						break;
					}
				}
				sum=num;
				for (int j=1;j<=n-1;j++)
				{
					sum=sum*j%M;
				}
				ans=ans+sum%M;
			}
		}
		cout<<ans/2;
	}
	else if (m==n && l==m)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
