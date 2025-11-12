#include <bits/stdc++.h>
using namespace std;

const int m = 998244353;
char s[505];
int c[505];

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> s[i];
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> c[i];
	}
	cout << m;
	return 0;
 } 
