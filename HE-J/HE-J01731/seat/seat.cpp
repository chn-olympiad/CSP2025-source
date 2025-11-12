#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
{
	return a > b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n * m + 1];
	for(int i = 1;i <= n * m; ++ i)
	 cin >> a[i];
	int x = a[1];
	sort(a + 1,a + (n * m) + 1,cmp);
	for(int i = 1;i <= n * m; ++ i)
	{
		if(a[i] == x)
		{
			if(i % n == 0)
			{
				int t = i / n;
				if(t % 2 == 0)
				 cout << t << " " << 1;
				else
				 cout << t << " " << m;
			}
			else
			{
				int t = i / n;
				t += 1;
				if(t % 2 == 0)
				 cout << t << " " << m - (i % n) + 1;
				else
				 cout << t << " " << i % n;
			}
			break;
		}
	}
	return 0;
}
