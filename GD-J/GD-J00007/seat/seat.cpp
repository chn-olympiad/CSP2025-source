#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r;
	int a[101];
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
	}
	int x = a[1],cnt = 0;
	sort(a+1,a+n*m+1);
	bool f = false;
	for(int i = 1;i <= n*m;i++)
	{
		if(f)
		{
			cnt++;
		}
		if(a[i] == x)
		{
			f = true;
		}
	}
	c = cnt / n + 1;
	if((cnt / n + 1)%2 == 0)
		r = n - cnt%n;
	else
		r = 1 + cnt%n;
	cout << c <<' '<< r;
	return 0;
}
