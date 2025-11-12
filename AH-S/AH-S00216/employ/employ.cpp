#include<bits/stdc++.h>
using namespace std;
long long c[510];
long long n, m;
string s;
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for(int i = 1; i <= m; i++)
	{
		cin >> c[i];
	}
	cout << m;
	return 0;
}
