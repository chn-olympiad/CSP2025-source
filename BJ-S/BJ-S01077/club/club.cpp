#include<bits/stdc++.h>
using namespace std;
struct students
{
      int a, b, c;
      int amore, bmore, cmore;
      int maxnum;
}stu[100005];
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int n;
    int ans = 0;
    cin >> n;
    while(n--)
    {
        int m;
        cin >> m;
        for(int i = 0; i < m; i++)
        {
            cin >> stu[i].a >> stu[i].b >> stu[i].c;
            if(stu[i].a >= stu[i].b && stu[i].a >= stu[i].c)
            {
                stu[i].maxnum = 1;
                stu[i].amore = stu[i].a - max(stu[i].b, stu[i].c);
            }

            if(stu[i].b >= stu[i].a && stu[i].b >= stu[i].c)
            {
                stu[i].maxnum = 2;
                stu[i].bmore = stu[i].b - max(stu[i].a, stu[i].c);
            }

            if(stu[i].c >= stu[i].b && stu[i].c >= stu[i].a)
            {
                stu[i].maxnum = 3;
                stu[i].amore = stu[i].c - max(stu[i].b, stu[i].a);
            }
        }
        int acnt = 0;
        int bcnt = 0;
        int ccnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(stu[i].maxnum == 1 && acnt + 1 <= m / 2)
            {
                acnt++;
                ans += stu[i].a;
            }
            else if(stu[i].maxnum == 1)
            {
                for(int j = 0; j < i; j++)
                {
                    if(stu[j].amore < stu[i].amore)
                    {
                        ans += stu[i].a;
                        ans += stu[j].amore;
                        ans -= stu[j].a;
                    }

                }
            }

            if(stu[i].maxnum == 2 && bcnt + 1 <= m / 2)
            {
                bcnt++;
                ans += stu[i].b;
            }
            else if(stu[i].maxnum == 1)
            {
                for(int j = 0; j < i; j++)
                {
                    if(stu[j].bmore < stu[i].bmore)
                    {
                        ans += stu[i].b;
                        ans += stu[j].bmore;
                        ans -= stu[j].b;
                    }

                }
            }

            if(stu[i].maxnum == 3 && ccnt + 1 <= m / 2)
            {
                ccnt++;
                ans += stu[i].c;
            }
            else if(stu[i].maxnum == 1)
            {
                for(int j = 0; j < i; j++)
                {
                    if(stu[j].amore < stu[i].cmore)
                    {
                        ans += stu[i].c;
                        ans += stu[j].cmore;
                        ans -= stu[j].c;
                    }

                }
            }
        }
        cout << ans << endl;
    }
    fclose(stdout);
    fclose(stdin);
    return 0;
}
