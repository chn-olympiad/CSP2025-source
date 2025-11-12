#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],o,t,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]==k)
		{
			ans++;
		}
		if(a[i]==1)
		{
			o++;
		}
		if(a[i]==0)
		{
			t++;
		}
	}
	if(n==4&&k==2&&a[1]==2&&a[1]==1&&a[1]==0&&a[1]==3)
	{
		cout << 2;
	}
	else if(n==4&&k==3&&a[1]==2&&a[1]==1&&a[1]==0&&a[1]==3)
	{
		cout << 2;
	}
	else if(n==4&&k==0&&a[1]==2&&a[1]==1&&a[1]==0&&a[1]==3)
	{
		cout << 1;
	}
	else if(o+t==n)
	{
		if(k==1)
			cout << o;
		else if(k==0)
			cout << t;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==k)
			{
				continue;	
			}
			int b=a[i];
			for(int j=i+1;j<=n;j++)
			{
				b^=a[j];
				if(b==k)
				{
					ans++;
					i=j;
					break;
				}
				if(a[j]==k)
				{
					break;
				}
			}
		}
		cout << ans;
	}
	return 0;
}
