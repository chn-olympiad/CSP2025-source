#include<bits/stdc++.h>
using namespace std;

int n, k, a[1000000], ans;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	
	if(k)
	{
		for(int i = 0; i < n; i++)
			if(a[i]) ans++;
	}
	else
	{
		for(int i = 0; i < n; i++)
		{
			if(a[i]) 
			{
				if(i + 1 < n && a[i + 1]) ans++, i++;
			}
			else ans++;
		}
	} 
		
	cout << ans;
	return 0;
}
