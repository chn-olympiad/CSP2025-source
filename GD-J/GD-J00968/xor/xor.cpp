#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
bool flag=1;
int n,k,num;
int a[N],sum[N];

void gc()
{
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if (a[i]!=a[i-1]&&i!=1)flag=0;
		sum[i]=sum[i-1]^a[i];
	}
	if (flag)
	{
		if (k==a[1])cout << n;
		else if (k==0)cout << n/2;
		else cout << 0;
		return;
	}
	int r=0;
	for (int j = 1;j <= n;j++)
	{
		for (int i = j;i > r;i--)
		{
			int kk = sum[j]^sum[i-1];
			if (kk==k)
			{
				num++;
				r=j;
				break;
			}
		}
	}
	cout << num;
	return;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	gc();
	return 0;
} 
