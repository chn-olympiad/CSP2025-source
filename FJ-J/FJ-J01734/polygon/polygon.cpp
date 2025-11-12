#include<bits/stdc++.h>
using namespace std;
long long c[5010], a[5010], n, s, b[5010][5010], x, y;
long long mod = 998244353;
void op()
{
	b[0][0] = 1;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 0;j <= i;j++)
		{
			if(j==0) b[i][j] = 1;
			else b[i][j] = b[i-1][j-1] + b[i-1][j];
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n <= 2)
	{
		cout<<0;
		return 0;
	}
	for(int i = 1;i <= n;i++) 
	{
		cin>>a[i];
		if(a[i]==1) x++;
		y += a[i];
		c[i] = c[i-1] + a[i];
	}
	op();
	if(x == n)
	{	
		for(int i = 3;i <= n;i++)
		{
			s += b[n][i];
		}
		cout<<s % mod;
		return 0;
	}
	sort(a + 1,a + n + 1);
	sort(c + 1,c + n + 1);
	if(n==3) 
	{
		if(a[1]+a[2]>a[3]) s++;
		cout<<s;
		return 0;
	}
	for(int i = 3;i <= n;i++)
	{
		s += b[n][i];
	}
	cout<<s % mod;
	return 0;
}

