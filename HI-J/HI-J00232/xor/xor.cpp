#include <bits/stdc++.h>
using namespace std;
int n,k,sum;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	int op = 0;
	for(int i = 1;i <= n;i++)
	{
		int q = 0;
		for(int j = i;j <= n;j++)
		{
			q = q^a[j];
			if(q == k)
			{
				if(op < i) 
				{
					sum++;
					op = j;
				}
				if(op > j)
					op = j;
				continue;
				continue;
			}	
		}
	}
	cout << sum;
	return 0;
}
