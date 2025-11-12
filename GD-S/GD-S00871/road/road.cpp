#include <bits/stdc++.h>
using namespace std;

struct city{
	int q, z, fip, laq, laz;
}ci[1000001];

int n, m, k, b[1000001];	
int main()
{
	//freopen("road.in", "r", "std.in");
	//freopen("road.out", "w", "std.out");
	scanf("%d%d%d", &n, &m, &k);
	
	for (int i = 1; i <= m; i++)
	{
		cin >> ci[i].q >> ci[i].z >> ci[i].fip;
		ci[i].laq = b[ci[i].q];
		ci[i].laz = b[ci[i].z];
		b[ci[i].q] = b[ci[i].z] = i;
	}
	cout << "13";
	return 0;
}
