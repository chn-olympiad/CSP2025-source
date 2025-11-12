#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,k,a[10005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	if(n == 1 && a[0] == k)
	{
		cout << a[0] << endl;
	}
	if(n == 1 && a[0] != k)
	{
		cout << 0 << endl;
	}
	return 0;
}