#include <bits/stdc++.h>
using namespace std;
int zgy_a[1005];
int main () 
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int zgy_n,zgy_m;
	cin >> zgy_n >> zgy_m;
	int zgy_s = zgy_n * zgy_m;
	for(int zgy_i = 0;zgy_i < zgy_s; ++zgy_i)
	{
		cin >> zgy_a[zgy_i];
	}
	int zgy_ans = zgy_a[1];
	sort(zgy_a,zgy_a + zgy_s);
	int zgy_j = 0;
	int zgy_w = 0;
	for(int zgy_i = zgy_s;zgy_i >= 0; --zgy_i)
	{
		zgy_w += 1;
		if(zgy_a[zgy_i] == zgy_ans)
		{
			zgy_j = zgy_w;
			break;
		}
	}
	int zgy_lie = 0;
	if(zgy_j % zgy_n == 0)
	{
		zgy_lie = zgy_j / zgy_n;
	}
	else
	{
		if(zgy_j < zgy_n)
		{
			zgy_lie = 1;
		}
		else
		{
			zgy_lie = zgy_j / zgy_n + 1;
		}
	}
	int zgy_k = zgy_j; 
	int zgy_han = 0;
	if(zgy_lie % 2 == 0)
	{
		zgy_han = zgy_n * zgy_lie - zgy_k + 1;
	}
	else
	{
		zgy_han = zgy_k - zgy_n * (zgy_lie - 1);
	}
	cout << zgy_lie << " " << zgy_han;
	return 0;
}
