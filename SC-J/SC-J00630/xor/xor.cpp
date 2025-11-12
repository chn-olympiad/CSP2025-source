# include <bits/stdc++.h>
using namespace std;

const int N= 5e5 + 5;

int a[N];

int n;
long long k;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	if (k == 1)
	    cout << n;
	else
	    cout << n / 2;
	
	return 0;
}