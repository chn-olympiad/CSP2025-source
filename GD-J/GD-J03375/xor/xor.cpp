#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
int l[500010];
int main()
{
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> l[i];		
	}
	if(k == 0)
	{
		int fl = 0;
		for(int i=1;i<=n;i++)
		{
			if(l[i] != 1) fl = 1;
		}
		if(!fl) cout << n/2;
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(l[i] == 0) ans++;
				else if(l[i-1] == 1 && l[i] == 1)
				{
					ans++;
				}
			}
			cout << ans;
		}
	}
	else if(k == 1)
	{
	    for(int i=1;i<=n;i++)
		{
			if(l[i] == 1) ans++;
		}
		cout << ans;
	}
	return 0;
}
