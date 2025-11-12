#include <bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("xor.in", "r", stdin);
	//freopen("xor.out", "w", stdout);
	string a;
	int lar = 0, j, lars = 0;
	cin >> a;
	int n = a.length();
	int b[n], c[n];
	for (int i = 0; i < n; i ++)
	{
		b[i] = (int)a[i];
	}
	for (int i = 0; i < n; i ++)
	{
		lar = 0, lars = 0;
		for ( j = 0; j < n; j ++)
		{
			if (b[j] > lar )
			{
				lar = b[j];
				lars = j;
			}
		}
		b[lars] = 0;
		//cout << lar << endl;
		if (lar >= 48 && lar <= 57)
		{
			cout << lar - 48;
		}
	}
	
	return 0;
}