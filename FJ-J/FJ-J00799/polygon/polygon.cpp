#include<bits/stdc++.h> 
using namespace std;
int a[105] = {}, cnt = 2, num;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	while(cnt < n)
	{
		num += n - cnt;
		cnt += 1;
	}
	cout << num % 998244353;
	return 0;
}
