#include <bits/stdc++.h>
using namespace std;
int x[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum = 0;
	cin >> n;
	int lz = INT_MIN;
	for(int i = 1;i<=n;i++)
	{
		cin >> x[i];
		sum += x[i];
		if(x[i]>lz)
		{
			lz = x[i];
		}
	}
	return 0;
}
