#include <bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n, k;
	cin >> n >> k;
	long long ans=0;
	for(int i=1;i<=n;i++)
	b[i]=1;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]==k)
		{
			ans++;
			b[i]=0;
		}
	}
	for(int i=1;i<=n-1;i++)
	for(int j=i+1;j<=n;j++)
	{
		int bj=1;
		long long cnt=0;
		for(int l=i;l<=j;l++)
		{
			cnt=cnt^a[l];
			if(b[l]==0)bj=0;
		}
		if(cnt==k&&bj==1)
		{
			for(int l=i;l<=j;l++)
			b[l]=0;
			ans++;
		}
	}
	cout << ans;
	return 0;
}