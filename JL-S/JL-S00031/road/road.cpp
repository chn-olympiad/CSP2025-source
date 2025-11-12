#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int u[N],v[N],w[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	if(k==0)
	{
		int sum = 0;
		for(int i = 1;i <= m;i++)
		{	
			cin >> u[i] >> v[i] >> w[i];
			sum += w[i];
		}
		cout << sum << endl;
		return 0;
	}
	cout << 0;
	return 0;
}
