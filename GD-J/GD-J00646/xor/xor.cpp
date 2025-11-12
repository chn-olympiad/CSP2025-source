#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[500005],f[3005],sa[1005][1005],last=-1;
int main()
{
	bool s1=true; 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	cin >> n >>k;
	for (int i=1;i<=n;i++) 
	{
		scanf("%lld",&a[i]);
		if (a[i]>1) s1=false;
	}
	if (n<=1000)
	{
		for (int i=1;i<=n;i++)
		{
			ll t;
			for (int j=i;j<=n;j++)
			{
				if (j==i) t=a[i];
				else t=t^a[j];
				sa[i][j]=t; 
			}
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=i;j++)
			{
				f[i]=max(f[i],f[j-1]+(sa[j][i]==k));
			}
		}
		cout << f[n];
	}
    else if (s1 && k==1)
	{
		int cnt = 0;
		for (int i=1;i<=n;i++) if (a[i]==1) cnt++;
		cout << cnt;
	}
	else if (s1 && k==0)
	{
		int cnt = 0;
		for (int i=1;i<=n;i++)
		{
			if (a[i]==0) cnt++;
			else if (last==1 && a[i]==1)
			{
				cnt++;
				last=-1;
			}
			else 
			{
				last=a[i];
			}
		}
		cout << cnt;
	}
}
