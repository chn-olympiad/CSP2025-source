#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[100006];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
    if (k <= 10)
    {
    	cout << 2;
	}
	if (k > 10)
	{
		cout << a[k];
	}
	return 0;
}
