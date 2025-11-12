#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define int long long
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;
struct node{
	int a1, a2, a3;
	int m1, m2, m3;
	int b1, b2;
	int p1, p2, p3;
} a[N];
int n;
bool cmp(node a1, node a2)
{
	if(a1.b1 == a2.b1)
	{
		return a1.b2 > a2.b2;
	}
	return a1.b1 > a2.b1;
}
int c[5], ans;
int T;
void init()
{
	memset(a, 0, sizeof(a));
	ans = 0;
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--)
	{
		init();
		cin >> n;
		for(int i = 1;i <= n;i ++)
		{
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			if(a[i].a1 >= a[i].a2)
			{
				if(a[i].a1 >= a[i].a3)
				{
					if(a[i].a2 >= a[i].a3)
					{
						a[i].p1 = 1;
						a[i].p2 = 2;
						a[i].p3 = 3;
						a[i].m1 = a[i].a1;
						a[i].m2 = a[i].a2;
						a[i].m3 = a[i].a3;
					}
					else
					{
						a[i].p1 = 1;
						a[i].p2 = 3;
						a[i].p3 = 2;
						a[i].m1 = a[i].a1;
						a[i].m2 = a[i].a3;
						a[i].m3 = a[i].a2;	
					}
				}
				else
				{
					a[i].p1 = 3;
					a[i].p2 = 1;
					a[i].p3 = 2;
					a[i].m1 = a[i].a3;
					a[i].m2 = a[i].a1;
					a[i].m3 = a[i].a2;
				}
			}
			else
			{
				if(a[i].a2 >= a[i].a3)
				{
					if(a[i].a1 >= a[i].a3)
					{
						a[i].p1 = 2;
						a[i].p2 = 1;
						a[i].p3 = 3;
						a[i].m1 = a[i].a2;
						a[i].m2 = a[i].a1;
						a[i].m3 = a[i].a3;
					}
					else
					{
						a[i].p1 = 2;
						a[i].p2 = 3;
						a[i].p3 = 1;
						a[i].m1 = a[i].a2;
						a[i].m2 = a[i].a3;
						a[i].m3 = a[i].a1;	
					}
				}
				else
				{
					a[i].p1 = 3;
					a[i].p2 = 2;
					a[i].p3 = 1;
					a[i].m1 = a[i].a3;
					a[i].m2 = a[i].a2;
					a[i].m3 = a[i].a1;
				}
			}
			a[i].b1 = a[i].m1 - a[i].m2;
			a[i].b2 = a[i].m2 - a[i].m3;
		}
		sort(a + 1, a + n + 1, cmp);
		c[1] = c[2] = c[3] = n / 2;
		for(int i = 1;i <= n;i ++)
		{
			if(c[a[i].p1])
			{
				c[a[i].p1] --;
				ans += a[i].m1;
			}
			else if(c[a[i].p2])
			{
				c[a[i].p2] --;
				ans += a[i].m2;
			}
			else{
				c[a[i].p3] --;
				ans += a[i].m3;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

