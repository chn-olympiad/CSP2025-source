#include<bits/stdc++.h>
using namespace std;
int n,m,q = 1,s = 1,r;//q为行,s为列
int a[100005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
		if(a[i] > a[1])
		{
			r = a[i + 1];
			if(r < a[i])
			{	
				if(s % 2 == 0)
				{
					q--;
				}
				q++;
				if(q > n)
				{
					q = q - n;
				}
			}	
			if(n == q)
			{
				s++;
			}
		}	
	}
	cout << s - 1 << " " << q;
	return 0;
}
