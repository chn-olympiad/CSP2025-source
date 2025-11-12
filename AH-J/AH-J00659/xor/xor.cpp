#include <bits/stdc++.h>
#define int long long
using namespace std;
int s[5000005];
int a[5000005];
int t[5000005];
int ck(int l,int r)
{
	for(int i=l;i<=r;i++) if (t[i]) return 0;
	return 1;
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum=0;
	cin>>n>>k;
	int mx=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
		s[i]=s[i-1]^a[i];
	}
	if (mx==1)
	{
		int rr=0;
		for(int i=1;i<=n;i++)
		{
			if (a[i]==k) rr++;
		}
		cout<<rr;
		return 0;
	}
	for(int d=1;d<=n;d++)
	{
		for(int i=1;i+d-1<=n;i++)
		{
			if ((int)(s[i+d-1]^s[i-1])==k&&ck(i,i+d-1))
			{
				for(int k=i;k<=i+d-1;k++)
					t[k]++;
				sum++;
			} 
		}
	}
	cout<<sum;
	return 0;
}
