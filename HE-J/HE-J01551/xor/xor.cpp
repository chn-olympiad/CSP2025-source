#include <bits/stdc++.h>
using namespace std;
int n,k,a[10000],l,r,b;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (1<=a[i]<=n)
		{
			r=k+r;
			if (l<a[i]<r)
			{
				b+=1;
			}
		}
	}
	cout<<b;
	return 0;
}
