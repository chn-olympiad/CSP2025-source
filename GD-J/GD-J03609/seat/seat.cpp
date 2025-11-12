#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
	int num,p;
}a[105];
bool cmp(node x,node y)
{
	return x.num > y.num;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x = 0,y = 1,cnt = 0,d = 1;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			cin >> a[(i - 1) * m + j].num;
			a[(i - 1) * m + j].p = (i - 1) * m + j;
		}	
	}
	sort(a + 1,a + n * m + 1,cmp);
	while(cnt < n * m)
	{
		if(y % 2 == 1 && x == n || y % 2 == 0 && x == 1)
		{
			y++;d = -d;
		}
		else x += d;
		cnt++;
		if(a[cnt].p == 1)
		{
			cout << y << " " << x << endl;
			return 0;
		}
	}
	return 0;
}
//100
