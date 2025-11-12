#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int b[5005];
int n;
const long long mod = 998244353;
int tot(int l,int r)
{
	int sum = 0;
	for (int i = l;i <= r;i++)
	{
		sum += b[i];
	}
	return sum;
}
int maxn(int l,int r)
{
	int maxx = -100;
	for (int i = l;i <= r;i++)
	{
		maxx = max(maxx,b[i]);
	}
	return maxx;
}
int a(int n,int m)
{
	int x = 1;
	while(n > 0)
	{
		x *= m;m--;n--;
	}
	return x;
}
int c(int n,int m)
{
	return a(n,m) / a(n,n);
}
bool check(int n,int m)
{
	return n > (m * 2);
}
int sum = 0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> b[i];
	}
	if (maxn(1,n) == 1) 
	{
		for (int i = 3;i <= n;i++)
		{
			sum += c(i,n);
		}
	}
	else
	{
		for (int i = 3;i <= n;i++)
		{
			for(int j = 1;j + i <= n;j++)
			{
				if (check(tot(i,j),maxn(i,j))) sum++;
			}
		}
	}
	cout << sum;
	return 0;
}
