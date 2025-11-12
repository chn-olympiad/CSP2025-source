#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	bool flag = true;
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
		if(a[i] == 0) flag = false;
	}
	if(flag)
	{
		if(k == 1)
			cout << n;
		if(k == 0)
			cout << n / 2;
	}
	else
	{
		
		int cnt = 0;
		for(int i = 0;i < n - 1;i++)
		{
			if(a[i] ^ a[i + 1] == k)
			{
				cnt++;
				i++;
			}
				
		}
		cout << cnt << endl;	
		
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
