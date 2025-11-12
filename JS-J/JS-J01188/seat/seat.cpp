#include <bits/stdc++.h>
using namespace std;
int n,m,a[110],t,c,r;
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++) cin >> a[i];
	t = a[1];
	sort(a + 1,a + 1 + n * m,cmp);
	for(int i = 1;i <= n * m;i++)
	{
		if(a[i] == t)
		{
			if(i % n) c = i / n + 1;
			else c = i / n;
			if(c % 2)
			{
				r = i % n;
				if(!r) r = n;
			}
			else
			{
				r = n - i % n;
				if(i % n) r += 1;
			}
			break;
		}
	}
	cout << c << ' ' << r;
	return 0;
}
