#include <bits/stdc++.h>
using namespace std;
int n,m,t,sum,h,l; 
int a[110];
bool cmp (int x,int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i ++)
	{
		cin >> a[i];
		if(i == 1) t = a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1; i <= n*m; i ++)
	{
		if(a[i] == t)
		{
			h = i%n;
			l = i/n;
			if(h > 0) 
			{
				l ++;
			}
			if(l%2 == 0) 
			{
				if(h == 0)
				{
					h = 1;
				}
				else
				{
					h = n - h + 1;
				}
			}
			else
			{
				if(h == 0)
				{
					h = n;
				}
			}
			cout << l << " " << h << "\n";
			break;
		}
	}
	return 0;
}
