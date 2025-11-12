#include<bits/stdc++.h>
#define mod 998244358;
using namespace std;
long long n, a[5005], ans, num[5005], vis[5005];
long long yjg(int i,int j,int q)
{
	long long ans2 = 1;
	for(int k = j + 1; k < i ; k++)
	{
		if(vis[k])
			continue;
		q += a[k];vis[k] = true;
		if(2 * a[i] < num[i] - num[j - 1] - q)
			{
				//cout << j << " " << i <<endl;
				ans2 += yjg(i, j , q) % mod;
			}
		q -= a[k];vis[k] = false;
	}
	
	return ans2;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if(n > 14)
	{
		cout << "no!" << endl;
		return 0;	
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i]; 
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
	{
		num[i] = num[i-1] + a[i]; 
	}
	for(int i = 3; i <= n; i++)
	{

		for(int j = i - 2; j >= 1; j--)
		{
			if(2 * a[i] < num[i] - num[j - 1])
			{
				//cout << j << " " << i <<endl;
				ans += yjg(i, j, 0) % mod;
			}
		}
	}
	cout << ans << endl;
	return 0;	
}
