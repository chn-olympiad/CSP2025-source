#include<bits/stdc++.h>
using namespace std;

int n, s;
int a[10000], b[10000];

void c(int i, int p[10000])
{
	int sum = 0, mx = 0;
	for(int j = 0; j < i; j++)
	{
		sum += a[p[j]];
		if(a[p[j]] > mx) mx = a[p[j]];
	}
	s = (s + (sum > 2 * mx)) % 998244353;
}
void f(int i, int j, int k, int p[10000])
{
	if(i == j + 1) c(i, p);
	for(int x = k + 1; x < n; x++)
	{
		p[j + 1] = x;
		f(i, j + 1, x, p);
	}
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	
	for(int i = 3; i <= n; i++)
	{
		f(i, -1, -1, b);
	}
	
	printf("%d", s);

	return 0;
}
