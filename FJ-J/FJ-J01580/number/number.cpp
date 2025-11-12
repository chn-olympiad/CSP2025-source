#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int zgy_a[N];
int main () 
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string zgy_s;
	cin >> zgy_s;
	int zgy_j = 0;
	for(int zgy_i = 0;zgy_i < zgy_s.size(); ++zgy_i)
	{
		if(zgy_s[zgy_i] >= '0' && zgy_s[zgy_i] <= '9')
		{
			zgy_a[zgy_j] = zgy_s[zgy_i] - '0';
			zgy_j++;	
			
		}
	}
	sort(zgy_a,zgy_a + zgy_j);
	for(int zgy_i = zgy_j - 1;zgy_i >= 0; --zgy_i)
	{
		cout << zgy_a[zgy_i];
	}
	return 0;
}
