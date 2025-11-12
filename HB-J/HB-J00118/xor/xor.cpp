#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000010],cnt;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","r",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	int t = a[1];
	for(int i = 1;i <= n;i++)
	{
		if(t == k)
		{
			cnt++;
			t = a[i];
		}
		else
			t ^= a[i];
	}
	if(t == k)
		cnt++;
	cout << cnt;
	return 0;
}
