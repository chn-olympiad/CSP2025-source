#include<bits/stdc++.h>
using namespace std;

priority_queue<long long, vector<long long>, greater<long long> > p; 

int main()
{

	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long n;
	bool ccf = 1;
	cin >> n;
	long long a[5001];
	
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		p.push(a[i]);
		if(a[i] != 1) ccf = 0;
	}
	if(ccf == 1)
	{
		ans = (n-2)*(n-1)/2;
		ans %= 988;
		ans %= 244;
		ans %= 353;
		cout << ans;
		return 0;
	}
	
	sort(a, a+n);
	long long lon, l = 0, ans = 0;
	for(int i = 3; i < n; i++)//多边形 
	{
		lon = a[0];
		for(int j = 0; j < i; j++)//木棍 
		{	
			lon = a[j];
			for(int k = 0; k < n; k++)
			{
				if(k == j)
				{
					break;
				}
				lon += a[k];
				else
				{
					if(lon > a[k]*2) ans++;
					else 
				}
			} 
		}
	}
	ans %= 988;
	ans %= 244;
	ans %= 353;
	cout << ans;

}