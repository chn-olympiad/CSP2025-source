#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], sum = 0;
bool pd[500005];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		pd[i] = 0;
		if (a[i] == k)
		{
			sum ++;
			pd[i] = 1;
		}
	}
	for (int i = 1; i <= n; i ++)
	{
		if (pd[i] == 0 && pd[i+1] == 0 && a[i]^a[i+1] == k)
		{
			pd[i] = pd[i+1] = 1;
			sum ++;
		} 
		else if (pd[i] == 0 && pd[i+1] == 0 && pd[i+2] == 0 && a[i]^a[i+1]^a[i+2] == k)
		{
			pd[i] = pd[i+1] = pd[i+2] = 1;
			sum ++;
		} 
	}	
	cout << sum;
	return 0;
}
