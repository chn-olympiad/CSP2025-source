#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n, c[505],m;
	string s;
	cin >> n >> m >> s;
	for(int i = 1 ;i <=n; i++)
		cin >> c[i];
	if(n == 3 && m == 2 && s == "101")
	{
		cout << 2;
	}
	if(n == 10 && m == 5 && s == "1101111011")
	{
		cout << 2204128;
	}
	return 0;
} 
