#include <bits/stdc++.h>
using namespace std;
int a[500010];
long long sa[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sa[i] = sa[i - 1] ^ a[i];
	}
	int cur = 1,ans = 0;
	for(int i = 1; i <= n; i++)
	{
		long long x = sa[i] ^ k;
		for(int j = i; j >= cur; j--)
		{
			if(x == sa[j - 1])
			{
				ans++;
				cur = i + 1;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
