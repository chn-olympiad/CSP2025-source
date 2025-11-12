#include<bits/stdc++.h>
using namespace std;
struct club
{
	int a , b , c;
	int zmy , cmy , bmy;
	int ch;
}cb[100010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for(int i = 1 ; i <= t ; i++)
	{	
		int n;
		long long sum = 0;
		int minn = 111111111;
		long long bm1 = 0 , bm2 = 0 , bm3 = 0;
		cin >> n;
		int bz = n/2;
		for(int j = 1 ; j <= n ; j++)
		{
			cin >> cb[j].a >> cb[j].b >> cb[j].c;
			if(cb[j].a >= cb[j].b && cb[j].b >= cb[j].c)
			{
				cb[j].zmy = cb[j].a;
				cb[j].cmy = cb[j].b;
				cb[j].bmy = cb[j].c;
				bm1++;
			}
			else if(cb[j].a >= cb[j].c && cb[j].c >= cb[j].b)
			{
				cb[j].zmy = cb[j].a;
				cb[j].cmy = cb[j].c;
				cb[j].bmy = cb[j].b;
				bm1++;
			}
			else if(cb[j].b >= cb[j].a && cb[j].a >= cb[j].c)
			{
				cb[j].zmy = cb[j].b;
				cb[j].cmy = cb[j].a;
				cb[j].bmy = cb[j].c;
				bm2++;
			}
			else if(cb[j].b >= cb[j].c && cb[j].c >= cb[j].a)
			{
				cb[j].zmy = cb[j].b;
				cb[j].cmy = cb[j].c;
				cb[j].bmy = cb[j].a;
				bm2++;
			}
			else if(cb[j].c >= cb[j].a && cb[j].a >= cb[j].b)
			{
				cb[j].zmy = cb[j].c;
				cb[j].cmy = cb[j].a;
				cb[j].bmy = cb[j].b;
				bm3++;
			}
			else if(cb[j].c >= cb[j].b && cb[j].b >= cb[j].a)
			{
				cb[j].zmy = cb[j].c;
				cb[j].cmy = cb[j].b;
				cb[j].bmy = cb[j].a;
				bm3++;
			}
			cb[j].ch = cb[j].zmy - cb[j].cmy;
			minn = min(cb[j].ch,minn);
			sum += cb[j].zmy;
		}
		if(bm1 > bz || bm2 > bz || bm3 > bz)
		{
			for(int j = 1 ; j <= n ; j++)
			{
				if(cb[j].ch == minn)
				{
					sum -= cb[j].zmy;
					sum += cb[j].cmy;
				}
			}
			cout << sum << endl;
		}
		else
		{
			cout << sum << endl;
		}
	}
	return 0;
}
