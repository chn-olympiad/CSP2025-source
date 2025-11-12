#include<bits/stdc++.h>
using namespace std;

long long n,k;

long long a[500005];
long long ans[500005],x;
long long num;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	
	for(long long i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	for(long long i = 1; i <= n; i++)
	{
		++x;
		ans[x] = a[i];
		if(ans[x] == k) 
		{
			x = 0;
			++num;
			continue;
		}
		
		for(long long j = 1; j < x; j++)
		{
			ans[j] = ans[j] ^ a[i];
			if(ans[j] == k) 
			{
				x = 0;
				++num;
			}
		}
	}
	
	cout << num;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
