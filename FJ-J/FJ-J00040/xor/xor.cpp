#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin >> n >> k;
	int a[500003];
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int f = 0;
		for(int j=i;j<=n;j++)
		{
			if(f^a[j] == k)
			{
				ans++;
				i=j+1;
				break;
			}
			else 
			{
				f+=j;
			}
		}
	}
	cout << ans;
	return 0;
}
