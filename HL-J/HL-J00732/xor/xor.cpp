#include <bits/stdc++.h>
using namespace std;

long long max_num;
long long a[500005];
long long b[500005];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	long long n,k;
	
	cin >> n >> k;
	
	for (long long i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	int num = 1;
	for (long long i = 1; i <= n; i++)
	{
		if (num > n) break;
		for (long long j = num; j <= n; j++)
		{
			int tmp = b[j-1] xor a[j];
			if (tmp == k)
			{
				max_num++;
				num = j + 1;
				break;
			}
			else
			{
				b[j] = tmp;
			}
		}
	}
	
	cout << max_num <<endl;
	return 0;	
} 
