#include<bits/stdc++.h>
using namespace std;
int m[1000005];
int u[10005];
int v[10005];
int w[10000000005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n , k , sum = 0;
	cin >> n >> k;
	for(int i = 0;i <= m;i++)
	{
		cin >> u[i];
		cin >> v[i];
		cin >> w[i];
		sum += w[i];
	}
	for(int i = 0;i <= m;i++)
	{
		sum += u[i];
	}
	cout << sum;
	return 0;	
}
