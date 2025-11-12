#include<bits/stdc++.h>
using namespace std;
int n,a1,a2,a3,maxxn;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n >> a1 >> a2 >> a3;
	maxxn = max(a1,a2);
	maxxn = max(maxxn,a3);
	if((a1 + a2 + a3) > maxxn * 2)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	return 0;
}
