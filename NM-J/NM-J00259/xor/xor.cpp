#include<bits/stdc++.h>
using namespace std;
int n,k;
long long a[500005];
long long ans;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >>n >>k;
    int num = 0;
    bool flag = true;
    for(int i = 1;i <= n;i++)
    {
        cin >>a[i];
        num += a[i];
        if (a[i] > 1)
        	flag = false;
    }
    if (num == n)
    {
    	cout << n/2;
    	return 0;
	}
	if (flag)
	{
		if (k == 1)
		{
			int ans = 0;
			for (int i = 1;i <= n;i++)
			{
				if (a[i] == 1)
					ans++;
				else if (a[i] == 0 && a[i+1] == 0)
				{
					ans++;
					i+=2;
				}
			}
			cout << ans;
		}
		if (k == 0)
		{
			int ans = 0;
			for (int i = 1;i <= n;i++)
			{
				if (a[i] == 0)
					ans++;
				else if (a[i] == 1 && a[i+1] == 1)
				{
					ans++;
					i+=2;
				}
			}
		}
		return 0;
	}
    for (int i = 1;i <= n;i++)
    {
        if (a[i] == k)
        {
            ans++;
            continue;
        }
        int num = a[i];
        for (int j = i +1;j <= n;j++)
        {
            num ^= a[j];
            if (num == k)
            {
                ans++;
                i = j+1;
            }
        }
    }
    cout <<ans;
    return 0;
}
