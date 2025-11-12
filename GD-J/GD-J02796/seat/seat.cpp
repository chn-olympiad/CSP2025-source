#include <bits/stdc++.h>
#include <cstdio>
int s[101];
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n , m , r , cnt = 0;
	int rl , rh;
	cin >> n >> m;
	for(int i = 0;i < n * m;i++)
	{
		cin >> s[i];
	}
	r = s[0];
	for(int i = 1;i < n * m;i++)
	{
		if(s[i] > r)
		{
			cnt++;
		}
	}
	cnt++;
	if(cnt % n == 0)
	{
		rl = cnt / n;
		if(rl % 2 == 1)
		{
			rh = n;
		}
		else
		{
			rh = 0;
		}
	}
	else
	{
		rl = cnt / n + 1;
		if(rl % 2 == 1)
		{
			rh  = cnt - (rl - 1) * n;
		}
		else
		{
			int p = cnt - (rl - 1) * n;
			rh = n + 1 - p;
		}
	}
	cout << rl << " " << rh;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
