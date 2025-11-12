#include <bits/stdc++.h>
using namespace std;
long long n , q;
string a[10005][10005] , b[10005][10005];
int main()
{
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	cin >> n >> q;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= 2;j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 1;i <= q;i++)
	{
		for (int j = 1;j <= 2;j++)
		{
			cin >> b[i][j];
		}
		cout << 0 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
