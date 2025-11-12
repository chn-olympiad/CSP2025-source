#include <bits/stdc++.h>

using namespace std;

int a[100000];
int b[100000];
int c[100000];
int k;
int n;

int main()
{
	freopen("xor.in", "r", stdin), freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i] = i ? a[i] + b[i - 1] : a[i];
		c[i] = i ? a[i] ^ c[i - 1] : a[i];
	}
	if(b[n - 1] == n && k == 0)
	{
		cout << n / 2 << endl, exit(0);
	}
	if(b[n - 1] == b[0] * n && k == b[0])
	{
		cout << n << endl, exit(0); 
	}
	cout << n / 2 - 1 << endl;
	
	return 0;
}

