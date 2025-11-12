#include <bits/stdc++.h>
using namespace std;

struct club
{
    int a1;
    int a2;
    int a3;
    int cur;
};

bool cmp(club a,club b)
{
    return a.a1 > b.a1;
}

void Main()
{
    int n;
    cin >> n;
    club a[100005] = {};
    bool mark1 = true;
    bool mark2 = true;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
        a[i].cur = i;
        if (a[i].a2 != 0 || a[i].a3 != 0)   mark1 = false;
        if (a[i].a3 != 0)   mark2 = false;
    }
    if (n == 2)
    {
        int tmp[10];
        tmp[1] = a[1].a1 + a[2].a2;
        tmp[2] = a[1].a1 + a[2].a3;
        tmp[3] = a[1].a2 + a[2].a1;
        tmp[4] = a[1].a2 + a[2].a3;
        tmp[5] = a[1].a3 + a[2].a1;
        tmp[6] = a[1].a3 + a[2].a2;
        cout << max(tmp[1],max(tmp[2],max(tmp[3],max(tmp[4],max(tmp[5],tmp[6]))))) << endl;
        return;
    }
    if (n == 4)
    {
        int ans = -1;
        int t[100];
        t[1] = a[1].a1 + a[2].a1 + a[3].a2 + a[4].a2;
        t[2] = a[1].a1 + a[2].a1 + a[3].a2 + a[4].a3;
        t[3] = a[1].a1 + a[2].a1 + a[3].a3 + a[4].a2;
        t[4] = a[1].a1 + a[2].a1 + a[3].a3 + a[4].a3;
        t[5] = a[1].a1 + a[2].a2 + a[3].a1 + a[4].a2;
        t[6] = a[1].a1 + a[2].a2 + a[3].a1 + a[4].a3;
        t[7] = a[1].a1 + a[2].a2 + a[3].a2 + a[4].a3;
        t[8] = a[1].a1 + a[2].a2 + a[3].a3 + a[4].a2;
        t[9] = a[1].a1 + a[2].a2 + a[3].a3 + a[4].a3;
        t[10] = a[1].a1 + a[2].a3 + a[3].a1 + a[4].a2;
        t[11] = a[1].a1 + a[2].a3 + a[3].a1 + a[4].a3;
        t[12] = a[1].a1 + a[2].a3 + a[3].a2 + a[4].a1;
        t[13] = a[1].a1 + a[2].a3 + a[3].a2 + a[4].a2;
        t[14] = a[1].a1 + a[2].a3 + a[3].a3 + a[4].a1;
        t[15] = a[1].a1 + a[2].a3 + a[3].a3 + a[4].a2;
        t[16] = a[1].a2 + a[2].a1 + a[3].a1 + a[4].a2;
        t[17] = a[1].a2 + a[2].a1 + a[3].a1 + a[4].a3;
        t[18] = a[1].a2 + a[2].a1 + a[3].a2 + a[4].a1;
        t[19] = a[1].a2 + a[2].a1 + a[3].a3 + a[4].a1;
        t[20] = a[1].a2 + a[2].a1 + a[3].a3 + a[4].a2;
        t[21] = a[1].a2 + a[2].a1 + a[3].a3 + a[4].a3;
        t[22] = a[1].a2 + a[2].a2 + a[3].a1 + a[4].a3;
        t[23] = a[1].a2 + a[2].a2 + a[3].a3 + a[4].a1;
        t[24] = a[1].a2 + a[2].a2 + a[3].a3 + a[4].a3;
        t[25] = a[1].a2 + a[2].a3 + a[3].a1 + a[4].a1;
        t[26] = a[1].a2 + a[2].a3 + a[3].a1 + a[4].a2;
        t[27] = a[1].a2 + a[2].a3 + a[3].a2 + a[4].a1;
        t[28] = a[1].a2 + a[2].a3 + a[3].a2 + a[4].a2;
        t[29] = a[1].a2 + a[2].a3 + a[3].a3 + a[4].a1;
        t[30] = a[1].a2 + a[2].a3 + a[3].a3 + a[4].a2;
        for (int i = 1;i <= 30;i++)
        {
            ans = max(ans,t[i]);
        }
        cout << ans;
        return;
    }
    if (mark1)
    {
        sort(a + 1,a + n + 1,cmp);
        int ans = 0;
        for (int i = 1;i <= n / 2;i++)
        {
            ans += a[i].a1;
        }
        cout << ans << endl;
        return;
    }
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin >> T;
    while (T--)
    {
        Main();
    }
    return 0;
}
