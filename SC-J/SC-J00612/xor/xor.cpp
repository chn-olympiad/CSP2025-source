#include<bits/stdc++.h>
using namespace std;

void z2(long long x)
{
	long long t = 1, i = 1;
	while(true)
	{
		if(i > x)
		{
			i--;
			break;
		}
		i++;
		t*=2;
	}
}

int main()
{

	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k;
	bool b;
	cin >> n >> k;
	long long a[10001];
	
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		if(a[i] != 1) b = 0;
	}
	if(b == 1)
	{
		cout << n*(n-1)/2;
		return 0;
	}
	
}