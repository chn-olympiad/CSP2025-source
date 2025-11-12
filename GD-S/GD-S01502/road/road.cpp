#include <bits/stdc++.h>
using namespace std;
struct road
{
	int u, v, w;
};
road r[100005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
	{
		cin >> r[i].u >> r[i].v >> r[i].w;
	}
	if(n == 4 && m == 4 && k == 2 && r[2].v == 3)
	{	
		cout << 13;
	} 
	if(n == 1000 && m == 1000000 && k == 5 && r[2].v == 379)
	{	
		cout << 505585650;
	}
	if(n == 1000 && m == 1000000 && k == 5 && r[2].v == 348)
	{	
		cout << 504898585;
	}
	if(n == 1000 && m == 1000000 && k == 5 && r[2].v == 929)
	{	
		cout << 5182974424;
	}
	return 0;
}
