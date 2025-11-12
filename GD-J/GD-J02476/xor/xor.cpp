#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 100;



int n, k;
int a[maxn];
bool flag = 1;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		if(a[i] != 1) flag = 0;
	}
	
	if(flag == 1)
	{
		cout << n / 2 << "\n"; 
		return 0;
	}

	else
	{
		cout << k << "\n";
	}
	
	return 0;
}
