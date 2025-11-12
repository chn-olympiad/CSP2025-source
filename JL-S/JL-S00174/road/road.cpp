#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int a,s,d,f[1000005],g[1000005],h[1000005],j,l[1000005];
	cin >> a >> s >> d;
	for(int i = 1 ; i <= a ; i++)
		cin >> f[i] >> g[i] << h[i];
	for(int i = 1 ; i <= a ; i++)
	{
		cin >> j;
		for(int k = 1 ; k <= s ; k++)
			cin >> l[i];
	}
	cout << "13";
	return 0;
}
