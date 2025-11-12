#include<bits/stdc++.h>
using namespace std;
int n,m,r,l,h;
int a[105];
int cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i ++)
	{
		cin >> a[i];
	}
	r = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	for(int i = 1;i <= n * m;i ++)
	{
		//cout << a[i] << " ";
		if(a[i] == r)
		{
			l = ceil(i / double(n));
			
			if(l % 2 != 0)
			{
				h = i - (l - 1) * n;
			}
			else
			{
				h = n - (i - (l - 1) * n) + 1;
			}
			
			break;
		}
	}
	cout << l << " " << h;
	return 0;
}


