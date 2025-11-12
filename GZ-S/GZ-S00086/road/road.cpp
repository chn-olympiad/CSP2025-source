//GZ-S00086 吴晨瑶 贵阳市第十八中学
#include <bits/stdc++.h> 
using namespace std;
int main()
{
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	int n,m,k,c = 0;
	cin >> n >> m >> k;
	int ui,vi,wi,ci;
	for (int i = 1; i <= m; i++)
	{
		cin >> ui >> vi >> wi;
		ci = ui + vi + wi;
		if (ci < (ci + 1))
		{
			c = (ci + 1);
		}
		else
		{
			c = ci;
		}
	}
	int d,ai,bi,di,ei;
	for (int j = 1; j <= k; j++)
	{
		cin >> d >> bi >> di >> ei;
	}
	cout << c;
	return 0;
}

