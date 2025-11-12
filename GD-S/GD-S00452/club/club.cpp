#include<iostream>
#include<algorithm>
using namespace std;

int t,n,c;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int z = 0;z < t;z++)
	{
		int a[100005],b[100005],p1 = 0,p2 = 0,ans = 0;
		cin >> n;
		for(int i = 1;i <= n;i++)
		{
			int x,y;
			cin >> x >> y >> c;
			if(x > y)
			{
				p1 += 1;
				a[p1] = x;
			}
			else
			{
				p2 += 1;
				b[p2] = y;
			}
		}
		sort(a + 1,a + p1 + 1);
		sort(b + 1,b + p2 + 1);
		for(int i = n;i > n / 2;i--) ans += a[i];
		for(int i = n;i > n / 2;i--) ans += b[i];
		cout << ans << endl;
	}
	return 0;
}
