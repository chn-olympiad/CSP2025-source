#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long n, m, k, maxn, sum;
long long u[N], v[N], w[N], d[N], a[N];
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		d[u[i]]++, d[v[i]]++;
		maxn = max(maxn, w[i]);
		sum += w[i];
	}
	for(int i=1;i<=m;i++)
	a[i] = w[i];
	sort(a+1, a+m+1);
	long long mm = m, s = 1;
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=m;i++)
		{
			if(mm == n-1)
			break;
			if(w[i] == maxn)
			{
				if(d[u[i]] >= 2 && d[v[i]] >= 2)
				{
					sum -= maxn;
					maxn = a[m - s];
					mm--, s++;
					break;
				}
			}
			if(i == m)maxn = a[m - s];
		}
	}
	cout<<sum<<endl;
	return 0;
}
