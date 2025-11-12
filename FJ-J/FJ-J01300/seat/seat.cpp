#include <bits/stdc++.h>
using namespace std;


long long n,m,a[1000],pos,ans1,ans2,pos2[1000];
bool cmp(long long h,long long j)
{
	return h > j;
}
int main()
{
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin >> n >> m;
	long long nn = n*m;
	for(long long i = 1;i <= n*m;i++)
	{
		cin >> a[i];
	}
	long long co = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(long long i = 1;i <= n*m;i++)
	{
		if(a[i] == co)
		{
			pos = i;
			break;
		}
	}
	for(long long i = 1;i <= m;i++)
	{
		for(long long j = 1;j <= n;j++)
		{
			pos -= 1;
			if(pos == 0)
			{
				ans1 = i;
				if(i % 2 == 1)
				{
					ans2 = j;
				}
				else
				{
					ans2 = n+1-j;
				}
				cout << ans1 << " "<< ans2;
				return 0;
			}
		}
	}
	
}
