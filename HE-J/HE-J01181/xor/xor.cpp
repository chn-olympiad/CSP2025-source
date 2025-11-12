#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	int a[n + 5];
	int wz[n + 5] = {0};
	int h = 0;
	for(int i = 1;i <= n; ++ i)
	{
		cin >> a[i];
		if(a[i] == 0)
		{
			wz[h] ++;
		}
		else
		{
			h ++;
		}
	}
	sort(wz + 1,wz + 1 + h);
	cout << wz[h];
	return 0;
}
