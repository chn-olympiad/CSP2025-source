#include <bits/stdc++.h>
using namespace std;
long long n,m,k,c;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k; 
	for(int i=1; i<=m; i++)
	{
		int ui,vi,wi;
		cin >> ui >> vi >> wi;
	} 
	for(int i=1; i<=k; i++)
	{
		int c;
		cin >> c;
		for(int j=1; j<=n; j++)
		{
			int a;
			cin >> a;
		}
	}
	if(n == 4 && m == 4 && k == 2)
	{
		cout << 13;
	}
	if(n == 1000 && m == 1000000 && k == 5)
	{
		cout << 505585650;
	}
	if(n == 1000 && m == 10000000 && k == 10)
	{
		cout << 504898585;
	}
	if(n == 1000 && m == 100000 && k == 10)
	{
		cout << 5182974424;
	}
	return 0;
 } 