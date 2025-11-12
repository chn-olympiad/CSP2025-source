#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int a[100005][5];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        int mx = n / 2;
        int go[100005];
        memset(go,0,sizeof go);
        int cnt1 = 0,cnt2 = 0,cnt3 = 0,lost = 0,ans = 0;
        for (int i = 1;i <= n;i++)
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
        for (int i = 1;i <= n;i++)
        {
            int g = max(a[i][1],max(a[i][2],a[i][3]));
            if (g == a[i][1])
            {
                cnt1++;
                go[i] = 1;
                ans += a[i][1];
            }
            else if (g == a[i][2])
            {
                cnt2++;
                go[i] = 2;
                ans += a[i][2];
            }
            else if (g == a[i][3])
            {
                cnt3++;
                go[i] = 3;
                ans += a[i][3];
            }
        }
        int change1[100005];
		if (cnt1 > mx)
		{
			int y = 1;
			for (int i = 1;i <= n;i++)
				if (go[i] == 1)
					change1[y++] = max(a[i][2],a[i][3]) - a[i][1];
			sort(change1,change1 + y,greater<int>());
			int o = cnt1 - mx;
			for (int i = 1;i <= o;i++)
				ans += change1[i];
		}
		if (cnt2 > mx)
		{
			int y = 1;
			for (int i = 1;i <= n;i++)
				if (go[i] == 2)
					change1[y++] = max(a[i][1],a[i][3]) - a[i][2];
			sort(change1,change1 + y,greater<int>());
			int o = cnt2 - mx;
			for (int i = 1;i <= o;i++)
				ans += change1[i];
		}	
		if (cnt3 > mx)
		{
			int y = 1;
			for (int i = 1;i <= n;i++)
				if (go[i] == 3)
					change1[y++] = max(a[i][2],a[i][1]) - a[i][3];
			sort(change1,change1 + y,greater<int>());
			int o = cnt3 - mx;
			for (int i = 1;i <= o;i++)
				ans += change1[i];
		}
		printf("%d\n",ans);
    }
    return 0;
}
