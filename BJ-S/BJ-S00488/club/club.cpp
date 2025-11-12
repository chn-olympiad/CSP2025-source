#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct Node
{
    int a[5], maxid, cha;
}stu[N];
vector<int> cnt[4];
bool cmp(int p, int q)
{
    return stu[p].cha < stu[q].cha;
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        int ans = 0;
        for(int i = 1;i <= 3;i++)
            cnt[i].clear();
        memset(stu, 0, sizeof(stu));
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= 3;j++)
                cin >> stu[i].a[j];
            int v[5];
            v[1] = stu[i].a[1], v[2] = stu[i].a[2], v[3] = stu[i].a[3];
            sort(v + 1, v + 4);
            for(int j = 1;j <= 3;j++)
                if(stu[i].a[j] == v[3])
                    stu[i].maxid = j;
            stu[i].cha = v[3] - v[2];
            //cout << "i: " << i << "  cha: " << stu[i].cha << "  max: " << stu[i].maxid << '\n';
            cnt[stu[i].maxid].push_back(i);
            ans += v[3];
        }
        int max1 = -1, maxcnt = -1;
        for(int i = 1;i <= 3;i++)
        {
            sort(cnt[i].begin(), cnt[i].end(), cmp);
            int tmp = cnt[i].size();
            if((int)cnt[i].size() >= max1)
                max1 = cnt[i].size(), maxcnt = i;
        }
        int x = -1;
        while(max1 > n / 2)
        {
            ans -= stu[ cnt[maxcnt][++x] ].cha;
            max1--;
        }
        cout << ans << '\n';
    }
    return 0;
}
/*
Ren5Jie4Di4Ling5%
*/