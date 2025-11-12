#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=1,a[1001];
int main()
{
	freopen("employ","r",stdin);
	freopen("employ","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[n];
	}
	if(m == n)
	{
		cout << 1;
	}
	else
	{
		for(int i=1;i<=m-1;i++)
		{
			sum *= i;
		}
	}
	cout << sum;
	return 0;
}
