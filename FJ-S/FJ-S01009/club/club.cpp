#include <bits/stdc++.h> 
using namespace std;
const int N = 1e5 + 5;
int t;
int n;
struct Stu{
	int x,y,z;
}a[N];
bool cmp(Stu p,Stu q)
{
	return p.x >= q.x;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		int s = 0;
		cin >> n;
		memset(a,0,sizeof(a));
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i].x >> a[i].y >> a[i].z;
		}
		sort(a + 1,a + n + 1,cmp);
		for(int i = 1;i <= n / 2;i++)
		{
			s += a[i].x;
		}
		cout << s;
	}
	return 0;
}
