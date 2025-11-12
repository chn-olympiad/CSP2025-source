#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500050];
long long sum,cnt;
bool ok=1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i]!=1)
			ok=0;
	}
	if(k==0&&ok==1)
	{
		cout << n;
		return 0;
	}
	for(int l = 1;l <= n;l++)
	{
		for(int r = l;r <= n;r++)
		{
			sum = 0;
			if(l==r)
				sum = a[l];
			else
			{
				sum = a[l];
				for(int k = l+1;k <= r;k++)
					sum = (sum^a[k]);
			}
			if(sum == k)
			{
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
