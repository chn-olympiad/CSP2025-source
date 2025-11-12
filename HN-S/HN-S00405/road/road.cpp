#include <iostream>
#include <algorithm>
using namespace std;
struct road
{
	int x,y,price;
}roads[1000005];
struct village
{
	int c,a[10005],zt=false;
}v[11];
bool city[10005];

int cmp(road a, road b)
{
	return a.price < b.price;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,num=1;
	long long w=0;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
		cin >> roads[i].x >> roads[i].y >> roads[i].price;
	for (int i = 1; i <= k; i++)
	{
		cin >> v[i].c;
		for (int j = 1; j <= n; j++)
			cin >> v[i].a[i];
	}
	sort(roads+1,roads+m+1,cmp);
//	for (int i = 1; i <= m; i++)
//		cout << roads[i].x << " " << roads[i].y << " " << roads[i].price <<"\n";
	city[roads[1].x] = true;
	city[roads[1].y] = true;
	for (int i = 1; i <= k; i++)
	{
		int vp = v[i].c + v[i].a[roads[1].x] + v[i].a[roads[1].y];
		if (vp < roads[1].price)
		{
			w += vp;
			v[i].zt = true;
		}
		else
			w += roads[1].price;
	}
	while (true)
	{
		for (int i = 1; i <= m; i++)
		{
			if (city[roads[i].x] ^ city[roads[i].y])
			{
				city[roads[i].x] = true;
				city[roads[i].y] = true;
				for (int i = 1; i <= k; i++)
				{
					int vp;
					if (v[i].zt) vp = v[i].a[roads[1].x] + v[i].a[roads[1].y];
					else vp = v[i].c + v[i].a[roads[1].x] + v[i].a[roads[1].y];
					if (vp < roads[i].price)
					{
						w += vp;
						v[i].zt = true;
					}
					else
						w += roads[i].price;
				}
				num++;
			}
			if (num == m-1)
			{
				cout << w;
				return 0;
			}
		}
	}
	return 0;
} 
