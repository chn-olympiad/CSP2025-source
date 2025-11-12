#include <iostream>
using namespace std;
struct node
{
	int x,y,w;
}a[1000005];
int c[15],s[15][10005];
bool v[15];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	long long ans = 0;
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)
		cin >> a[i].x >> a[i].y >> a[i].w;
	for(int i = 1;i <= k;i++)
	{
		cin >> c[i];
		for(int j = 1;j <= n;j++) cin >> s[i][j];
	}
	for(int i = 1;i <= m;i++)
	{
		int minn = a[i].w,mp = 0;
		for(int j = 1;j <= k;j++)
		{
			int e = s[j][a[i].x] + s[j][a[i].y] + (1 - v[j]) * c[j];
			if(e < minn) minn = e,mp = j;
		}
		ans += minn;
		if(!v[mp]) ans += c[mp],v[mp] = 1;
	}
	cout << ans << endl;
	return 0;
}
