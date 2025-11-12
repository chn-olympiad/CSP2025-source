#include <bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long x=0;
	int num=0;
	for (int i=1;i<=n;i++)
	{
		x^=a[i];
		if (x==k)
		{
			x=0;
			num++;
		}
	}
	cout<<num;
	return 0;
}
