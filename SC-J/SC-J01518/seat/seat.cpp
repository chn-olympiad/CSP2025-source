#include <bits/stdc++.h>
using namespace std;
struct stu
{
	int x,id;
};
stu a[105];
bool cmp(stu A,stu B)
{
	return A.x > B.x;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
	{
		cin >> a[i].x;
		a[i].id = i;
	}
	sort(a + 1,a + n * m + 1,cmp);
	for(int i = 1; i <= m; i++)
	{
		if(i % 2 == 1)
		{
			for(int j = 1; j <= n; j++)
			{
				if(a[(i - 1) * n + j].id == 1)
				{
					cout << i << " " << j << endl;
					return 0;
				}
			}
		}
		else
		{
			for(int j = n; j >= 1; j--)
			{
				if(a[(i - 1) * n + (n - j + 1)].id == 1)
				{
					cout << i << " " << j << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
