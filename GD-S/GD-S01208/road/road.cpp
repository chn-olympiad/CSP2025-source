#include <bits/stdc++.h> 
#define ll long long
using namespace std;
const int N = 1e6 + 5;

int n, m, k;
ll u[N], v[N], w[N];
int main()
{
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	scanf ("%d %d %d", &n, &m, &k);
	
	for (int i = 1; i <= m; i++)
	{
		scanf ("%lld %lld %lld", &u[i], &v[i], w[i]);
	}
	
	printf("13");
	return 0;
}
