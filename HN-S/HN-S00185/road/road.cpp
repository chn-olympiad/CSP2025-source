#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m, k;
int h[N], ne[N], e[N], w[N], idx;
void add(int a, int b, int c)
{
	w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(h, -1, sizeof h);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
		add(y, x, z);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

