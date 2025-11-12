#include <iostream> 
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct poi
{
	int x, y, z;
}a[100005];

void init()
{
	memset(a, 0, sizeof(a));
}

bool cmpx(poi x, poi y) { return x.x > y.x;}
bool cmpy(poi x, poi y) { return x.y > y.y;}
bool cmpz(poi x, poi y) { return x.z > y.z;}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		init();
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		sort(a + 1, a + n + 1, cmpx);
		int ans = 0, sum = 0;
		for(int i = 1; i <= n/2;i++)sum += a[i].x;
		for(int i = n / 2 + 1; i <= n; i++) sum += max(a[i].y, a[i].z);
		ans = max(ans, sum);
		sum = 0;
		sort(a + 1, a + n + 1, cmpy);
		for(int i = 1; i <= n/2;i++)sum += a[i].y;
		for(int i = n / 2 + 1; i <= n; i++) sum += max(a[i].x, a[i].z);
		ans = max(ans, sum);
		sum = 0;
		sort(a + 1, a + n + 1, cmpz);
		for(int i = 1; i <= n/2;i++)sum += a[i].z;
		for(int i = n / 2 + 1; i <= n; i++) sum += max(a[i].y, a[i].x);
		ans = max(ans, sum);
		sum = 0;
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
