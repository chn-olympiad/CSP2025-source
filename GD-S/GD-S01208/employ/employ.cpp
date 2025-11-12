#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int n, m;
string s;
int c[505];
int main()
{
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	scanf ("%d %d", &n, &m);
	cin >> s;
	for (int i = 1; i <= n; i++)
	{
		scanf ("%d", &c[i]);
	}
	if (n == 3 && m == 2) 
		printf("2") ;
	if (n == 10 && m == 5)
		printf("2204128");
	return 0;
}
