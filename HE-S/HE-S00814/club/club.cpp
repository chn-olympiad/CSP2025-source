#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int T;
int n;
struct Node{
	int x, y, z;
}a[maxn];
inline bool cmp1(Node xx, Node yy)//x½µÐò
{
	return xx.x > yy.x;
}
inline bool cmp2(Node xx, Node yy)//y½µÐò
{
	return xx.y > yy.y;
}
inline bool cmp3(Node xx, Node yy)//z½µÐò
{
	return xx.z > yy.z;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i].x >> a[i].y >> a[i].z;
		int ans = 0;
		//x½µÐò
		sort(a + 1, a + 1 + n, cmp1);
		int res = 0;
		for(int i = 1; i <= (n >> 1); i++)
			res += a[i].x;
		for(int i = (n >> 1) + 1; i <= n; i++)
			res += max(a[i].y, a[i].z);
		ans = max(ans, res);
		//y½µÐò
		sort(a + 1, a + 1 + n, cmp2);
		res = 0;
		for(int i = 1; i <= (n >> 1); i++)
			res += a[i].y;
		for(int i = (n >> 1) + 1; i <= n; i++)
			res += max(a[i].x, a[i].z);
		ans = max(ans, res);
		//z½µÐò
		sort(a + 1, a + 1 + n, cmp3);
		res = 0;
		for(int i = 1; i <= (n >> 1); i++)
			res += a[i].z;
		for(int i = (n >> 1) + 1; i <= n; i++)
			res += max(a[i].x, a[i].y);
		ans = max(ans, res);
		cout << ans << endl;
	}
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

const unsigned long long rp = LLONG_MAX
*/
