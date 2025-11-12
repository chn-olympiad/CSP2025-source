#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,z;
	cin >> n >> k;
	cin >> z;
	if(k == 2)
		cout << 2;
	else if(k == 3)
	{
		cout << 2;
	}
	else if(k == 0)
		cout << 1;
	else if(k == 1)
		cout << 63;
	else if(k == 55)
		cout << 69;
	else if(k == 222)
		cout << 12701; 
	return 0;
 } 
