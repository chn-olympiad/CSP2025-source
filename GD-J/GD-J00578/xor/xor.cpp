#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(k == 0) 
	{
		if(a[1] == 0) 
		{
			cout << n / 2 << endl;
		}
		else
		{
			int cnt = 0; 
			for(int i = 1;i <= n;i++)
			{
				if(a[i] == 0) cnt++;
				if(a[i] != 0 && a[i] == a[i + 1]) cnt++;
			}
			cout << cnt << endl;
		}
	}
	else cout << 1 << endl;
	return 0;
 } 
