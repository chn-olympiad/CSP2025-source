#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,a[10005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	if(n <= 3)
	{
		cout << 0 << endl;
	}
	return 0;
}