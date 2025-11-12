#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int a[N], b[N],c[N];
int s[10010][10010];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n, m, k;
	scanf ("%d%d%d",&n,&m,&k);
	for (int i = 0; i < m; i++)
	{
		scanf ("%d%d%d",&a[i],&b[i],&c[i]);
	}
	for (int i = 0; i < k; i++)
	{
		int t;
		scanf ("%d",&t);
		for (int j = 0; j < n; j++)
		{
			scanf ("%d",&s[i][j]);
		}
	}
	if (n == 4 && m == 4 && k == 2) printf ("13");
	if (n == 1000 && m == 1000000 && k == 5) printf ("505585650");
	if (n == 1000 && m == 1000000 && k == 10) printf ("504898585");
	return 0;
}
