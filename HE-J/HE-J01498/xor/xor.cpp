#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin >>n >>k;
	int a[n+1];
	for (int i=1;i<=n;i++)
	{
		cin >>a[i];
	}
	long long start=1;
	long long ans=0;
	while (start<=n)
	{
		long long t=a[start];
		if (t==k)
		{
			ans++;
			start++;
			continue;
		}
		for (long long i=start+1;i<=n;i++)
		{
			t=t^a[i];
			if(t==k)
			{
				start=i+1;
				ans++;
				continue;
			}
		}
		start++;
	}
	cout <<ans;
	return 0;
}
