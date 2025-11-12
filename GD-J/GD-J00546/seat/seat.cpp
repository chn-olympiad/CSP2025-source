#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],s[105],xy,ansx,ansy;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
		s[i] = a[i];
	}
	for(int i = 1;i <= n*m;i++)
	{
		for(int j = 1;j < n*m;j++)
		{
			if(s[j] < s[j+1])
			{
				int t = s[j];
				s[j] = s[j+1];
				s[j+1] = t;
			}
		}
	}
	for(int i = 1;i <= n*m;i++)
	{
		if(a[1] == s[i])
		{
			xy = i;
			break;
		}
	}
	ansx = xy/n;
	double byt = xy,drb = n;
	if(byt/drb != ansx)
	{
		ansx += 1;
	}
	xy -= (ansx-1)*n;
	cout << ansx << " ";
	if(ansx % 2 == 0)
	{
		cout << n-xy+1;
	}
	else
	{
		cout << xy;
	}
	return 0;
}
