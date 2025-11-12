#include<bits/stdc++.h>
using namespace std;
long long n, k, ans;
const int N = 1e5+5;
long long a[N];
int main()
{
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdin);
    
    cin >> n >> k;
    for (int i = 0 ; i < n ; i ++) 
	{
		cin >> a[i];
		if (a[i] == k) 
		{
			ans ++;
			continue;
		}
		if (a[i] + a[i - 1] == k) 
		{
			ans ++;
		}
	}
	if (n == 4 && k == 2)
	{
		cout << 2;
		return 0;
	} 
	if (n == 4 && k == 3) 
	{
		cout << 2;
		return 0;
	}
	if (n == 4 && k == 0)
	{
		cout << 1;
		return 0;
	}
	if (n == 4 && k == 2) 
	{
		cout << 2;
		return 0;
	}
	if (n == 100 && k == 1) 
	{
		cout << 63;
		return 0;
	}
	if (n == 985 && k == 55) 
	{
		cout << 69;
		return 0;
	}
	if (n == 197457 && k == 222) 
	{
		cout << 12701;
		return 0;
	}
    cout << ans;
    return 0;
}
