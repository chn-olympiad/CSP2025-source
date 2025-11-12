#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    int a[n];
    bool fg1 = 0,fg2 = 0;
    for(int i = 0;i < n; ++ i)
    {
    	cin >> a[i];
    	if(a[i] != 1)
    	 fg1 = 1;
    	if(a[i] > 1)
    	 fg2 = 1;
	}
	if(fg1 == 0)
	{
		if(k == 0)
		{
			if(n == 1)
			 cout << 0;
			else if(n == 2)
			 cout << 1;
			else
			{
				if(n % 2 == 0)
				 cout << n / 2;
				else
	             cout << (n - 1) / 2;
			}
		}
	}
	else if(fg2 == 0)
	{
		if(k == 1)
		{
			int ans = 0;
			int t = 0;
			for(int i = 0;i < n; ++ i)
			{
				if(a[i] == 1)
				{
				    ans += 1;
				    if(t != 0)
				    {
				    	t = 0;
					}
				}
				else if(a[i] == 0)
				 t += 1;
			}
			cout << ans;
		}
		else if(k == 0)
		{
			int ans = 0;
			int t = 0;
			for(int i = 0;i < n; ++ i)
			{
				if(a[i] == 0)
				{
					ans += 1;
					t = 0;
				}
				else if(a[i] == 1)
				{
					t += 1;
					if(t == 2)
					{
						t = 0;
						ans += 1;
					}
				}
			}
			cout << ans;
		}
	}
	return 0;
}
