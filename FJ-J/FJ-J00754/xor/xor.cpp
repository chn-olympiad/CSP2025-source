#include <bits/stdc++.h>
#include <complex>
int n,a[500005];
int sum[500005];
long long k;
using namespace std;
int find(int l,int r)
{
	int cnt = 0;
	int pos = l;
	for (int i = l;i <= r;i++)
	{
		if ((sum[i] ^ sum[pos-1]) == k)
		{
			cnt++;
			pos = i+1;
		}
	}
	return cnt;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	sum[1] = a[1];
	for (int i = 2;i <= n;i++)
	{
		sum[i] = sum[i-1] ^ a[i];
	}
	int maxx = -1;
	for (int i = 1;i <= n;i++)
	{
		for (int j = i;j <= n;j++)
			maxx = max(maxx,find(i,j));
	}
	cout << maxx;
	return 0;
}


