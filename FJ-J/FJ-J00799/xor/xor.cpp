#include<bits/stdc++.h> 
using namespace std;
int a[105] = {}, cnt = 1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n, k;
	cin >> n >> k;
	if(k == 1)
	{
		for(int i=1; i<=n; i++)
		{
			cin >> a[i];
			if(a[i] == 0)
			{
				cnt++;
			}
		}
		cout << cnt + (n - cnt) / 2;
	}
	else
	{
		for(int i=1; i<=n; i++)
		{
			cin >> a[i];
			if(a[i] == 1)
			{
				cnt++;
			}
		}
		cout << cnt;
	}
	return 0;
}
