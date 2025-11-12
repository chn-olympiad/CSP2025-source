#include<bits/stdc++.h>
using namespace std;
int a[100010];
int b[100010];
int c[100010];
int s[100010];
long long x = 0, y = 0, z = 0;
long long tx = 0, ty = 0, tz = 0;
long long ret = 0;
int n;
void sun (int t)
{
	
	if (t == n)
	{
		if (x+y+z > ret) ret = x+y+z;
		//printf ("%d %d %d %d\n",x,y,z,ret);
		return ;
	}
	if (tx < n/2)
	{
		x += a[t];
		tx++;
		sun(t+1);
		x -= a[t];
		tx--;
	}
	if (ty < n/2)
	{
		y += b[t];
		ty++;
		sun(t+1);
		y -= b[t];
		ty--;
	}
	if (tz < n/2)
	{
		z += c[t];
		tz++;
		sun(t+1);
		z -= c[t];
		tz--;
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf ("%d",&t);
	while (t--)
	{
		scanf ("%d",&n);
		ret = 0;
		x = 0, y = 0, z = 0;
		tx = 0, ty = 0, tz = 0;
		for (int i = 0; i < n; i++)
		{
			scanf ("%d%d%d",&a[i],&b[i],&c[i]);
		}
		sun(0);
		printf ("%lld\n",ret);
	}
	return 0;
}
