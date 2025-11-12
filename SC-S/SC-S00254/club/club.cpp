#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int t, n, maxx;
struct Node
{
	int x, y, z;
}a[N];
bool cmp (Node x, Node y)
{
	return x.x > y.x;
}
bool cmp1 (Node x, Node y)
{
	if (x.x != y.x) return x.x > y.x; 
	if (x.y != y.y) return x.y > y.y;
	return x.z > y.z; 
}
int main ()
{
    freopen ("club.in", "r", stdin);
    freopen ("club.out", "w", stdout);
    cin >> t;
    while (t --)
    {
    	int bjt = 1, ans = 0;
    	cin >> n;
    	maxx = n / 2;
    	for (int i = 1;i <= n;i ++)
    	{
    		cin >> a[i].x >> a[i].y >> a[i].z;
    		if (!(a[i].y == 0 && a[i].z == 0))
    		{
    			bjt = 0;
			}
		}
		if (bjt)
		{
			sort (a + 1, a + n + 1, cmp);
//			for (int i = 1;i <= n;i ++)  
//			{
//				cout << a[i].x << " " << a[i].y << " " << a[i].z << endl; 
//			 } 
			for (int i = 1;i <= maxx;i ++)
			{
				ans += a[i].x;
			}
			cout << ans << "\n";
		}
		else
		{
			sort (a + 1, a + n + 1, cmp1);
//			for (int i = 1;i <= n;i ++)   
//			{
//				cout << a[i].x << " " << a[i].y << " " << a[i].z << endl; 
//			 } 
			for (int i = 1;i <= maxx;i ++)
			{
				ans += a[i].x;
			}
			for (int i = maxx + 1;i <= n;i ++)
			{
			 	ans += a[i].y;
			}
			cout << ans << endl;
		} 
	}
    return 0;
}
//让我这样拿个奖吧
//I want something just like this
//drink保佑我啊 