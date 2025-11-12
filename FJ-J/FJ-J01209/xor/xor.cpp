#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a[1003],n,k,b[1005],sum=0;
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> b[i];
	}
	for(int i = 1;i <= n;i++)
	{
		a[i]=b[i];
		if(b[i]==k)
		{
			sum++;
		}
		for(int j = i+1;j <= n;j++)
		{
			a[j]=a[j-1]^b[j];	
			if(a[j]==k)
			{
				sum++;
			}
		}
	}
	cout << sum;
	return 0;
}
