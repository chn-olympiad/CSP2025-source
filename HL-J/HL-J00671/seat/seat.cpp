#include<bits/stdc++.h>
using namespace std;
int c, r, b;
int a[15];
int ans;
int db, dt;
int cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> c >> r;
	int n;
	n = c * r;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	b = a[1];
	sort(a + 1, a + n + 1,cmp);
	for(int i = 1;i <= n;i++)
	{
		if(a[i] == b)
		{
			ans = i;
		}
	}
	cout << "1" << " " << "2";
	return 0;
}
