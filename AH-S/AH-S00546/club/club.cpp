#include <bits/stdc++.h>
using namespace std;
int T,n;
struct STU
{
    int x,y,z;
}a[100005];
bool cmp1(STU o,STU p)
{
	return o.x > p.x;
}
bool cmp2(STU o,STU p)
{
	return o.y > p.y;
}
bool cmp3(STU o,STU p)
{
	return o.z > p.z;
}
int main()
{
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> T;
    while(T--)
    {
        cin >> n;
        long long ans = 0,endnum = 0;
        bool ok1 = true,ok2 = true;
        for(int i = 1; i <= n; i++)
        {
			cin >> a[i].x >> a[i].y >> a[i].z;
			if(a[i].y != 0 || a[i].z != 0)
			{
				ok1 = false;
			}
			if(a[i].z != 0)
			{
				ok2 = false;
			}
        }
        
        if(ok1)
        {
			sort(a + 1,a + n + 1,cmp1);
			for(int i = 1; i <= n / 2; i++)
			{
				ans += a[i].x;
			}
			cout << ans;
			continue;
		}
        if(n == 2)
        {
			int fu = 0;
			fu = max(a[1].x + a[2].y,a[1].x + a[2].z);
			fu = max(fu,max(a[1].y + a[2].x,a[1].y + a[2].z));
			fu = max(fu,max(a[1].z + a[2].x,a[1].z + a[2].y));
			cout << fu;
			continue;
		}
        sort(a + 1,a + n + 1,cmp1);
        for(int i = 1; i <= n / 2; i++)
			ans += a[i].x;
		for(int i = n / 2 + 1; i <= n; i++)
			ans += max(a[i].y,a[i].z);
		endnum = max(endnum,ans);
		ans = 0;
		sort(a + 1,a + n + 1,cmp2);
        for(int i = 1; i <= n / 2; i++)
			ans += a[i].y;
		for(int i = n / 2 + 1; i <= n; i++)
			ans += max(a[i].x,a[i].z);
		endnum = max(endnum,ans);
		ans = 0;
		sort(a + 1,a + n + 1,cmp3);
        for(int i = 1; i <= n / 2; i++)
			ans += a[i].z;
		for(int i = n / 2 + 1; i <= n; i++)
			ans += max(a[i].x,a[i].y);
		endnum = max(endnum,ans);
		cout << endnum << endl;
    }
    return 0;
}
