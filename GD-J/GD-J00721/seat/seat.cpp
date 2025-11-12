#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
const int N = 15;
int n,m,t,x = 1,y = 1;
struct stu
{
	int pts,id;
}a[N * N];
bool cmp(stu A,stu B)
{
	return A.pts > B.pts;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	t = n * m;
	for(int i = 1;i <= t;i++)
	{
		cin >> a[i].pts;
		a[i].id = i;
	}
	sort(a + 1,a + 1 + t,cmp);
	for(int i = 1;i <= t;i++)
	{
		if(a[i].id == 1)
		{
			cout << y << ' ' << x;
			return 0;
		}
		if(y % 2 == 0)
		{
			x--;
			if(x == 0)
			{
				x = 1;
				y++;
			}
		}
		else
		{
			x++;
			if(x == n + 1)
			{
				x = n;
				y++;
			}
		}
	}
	return 0;
}

