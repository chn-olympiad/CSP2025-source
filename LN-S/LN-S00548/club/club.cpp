#include <bits/stdc++.h>
using namespace std;
struct node
{
    int num,m,pos,type;
    bool operator < (const node k) const
    {
        return m > k.m;
    }
};
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,num1,num2,num3;
    cin >> t;
    while (t--)
    {
        int ans = 0,cnt[4] = {0},id = 0,cn = 0;
        bool b[100002]={0};
        node a[100002];
        cin >> n;
        for (int i = 1;i <= n;i++)
        {
            cin >> num1 >> num2 >> num3;
            ans += num1;
            a[++id].m = num2-num1; a[id].pos = i; a[id].type = 2; a[id].num = num2;
            // cout << a[id].m << ' ' << a[id].pos << ' ' << a[id].type << '\n';
            a[++id].m = num3-num1; a[id].pos = i; a[id].type = 3; a[id].num = num3;
            //cout << a[id].m << ' ' << a[id].pos << ' ' << a[id].type << '\n';

        }
        //cout << '\n';
        sort(a+1,a+2*n+1);
        for (int i = 1;i <= 2*n;i++)
        {
            if (cn < n/2)
            {
                if (b[a[i].pos] == 0 && cnt[a[i].type] < n/2)
                {
        //            if (a[i].pos == 2 && a[i].type == 3) cout << a[i].m << '\n';
                    //cout << a[i].pos << ' ' << a[i].type  << ' ' << a[i].num << ' ' << a[i].m << '\n';
                    ans += a[i].m;
                    b[a[i].pos] = 1; cnt[a[i].type] ++;
                    cn++;
                }
            }
            else
            {
                if (a[i].m <= 0) break;
                if (b[a[i].pos] == 0 && cnt[a[i].type] < n/2)
                {
                    //cout << a[i].pos << ' ' << a[i].type << ' ' << a[i].num << ' ' << a[i].m << '\n';
                    ans += a[i].m;
                    b[a[i].pos] = 1; cnt[a[i].type]++;
                    cn++;
                }
            }
        }
        cout << ans << '\n';
    }
///!!clear
    return 0;
}
