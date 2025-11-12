#include <bits/stdc++.h>
using namespace std;
int main () 
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int zgy_a,zgy_s;
	cin >> zgy_a >> zgy_s;
	if(zgy_a == 2)
	{
		int zgy_q,zgy_w;
		cin >> zgy_q >> zgy_w;
		cout << (zgy_q ^ zgy_w);
		return 0;
	}
	else
	{
		int zgy_q;
		cin >> zgy_q;
		cout << zgy_q;
		return 0;
	}
	if(zgy_s == 0)
	{
		cout << 1;
	}
	return 0;
}
