#include <bits/stdc++.h>
using namespace std;
void tonext(int& x, int& y, int m, int n)
{
	if(x & 1)
	{
		if(y == n){
			++x;
			return;
		}
		++y;
		return;
	}
	else
	{
		if(y == 1)
		{
			++x;
			return;
		}
		--y;
		return;
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m, n; cin >> n >> m;
	vector<int> scr = {};
	
	for(int i = 0; i < n; ++ i)
	{
		for(int j = 0; j < m; ++ j)
		{
			int tmp; cin >> tmp;
			scr.push_back(tmp);
		}
	}
	
	int rk = 1, a1 = scr[0];
	for(auto i : scr)
	{
		if(i > a1)
		{
			++rk;
		}
	}
	
	int x = 1, y = 1;
	while(--rk > 0)
	{
		tonext(x, y, m, n);
	}
	cout << x << " " << y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

