#include<cmath>
#include<queue>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 10;

int f[N];
int a[5][N];

struct node
{
    int id;
    int l1,l2;
    bool operator < (const node &x) const
    {
        return max(l1,l2) < max(x.l1,x.l2);
    }
};
priority_queue<node> q1,q2,q3;

signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> a[1][i] >> a[2][i] >> a[3][i];
        int cnt1 = 0;
        int cnt2 = 0;
        int cnt3 = 0;
        int ans = 0;
        while(!q1.empty()) q1.pop();
        while(!q2.empty()) q2.pop();
        while(!q3.empty()) q3.pop();
        for(int i = 1; i <= n; i++)
        {
            if(a[1][i] >= a[2][i] && a[1][i] >= a[3][i])
            {
                cnt1++;
                f[i] = 1;
                ans += a[1][i];
                q1.push({i,a[2][i] - a[1][i],a[3][i] - a[1][i]});
                continue;
            }
            if(a[2][i] >= a[1][i] && a[2][i] >= a[3][i])
            {
                cnt2++;
                f[i] = 2;
                ans += a[2][i];
                q2.push({i,a[1][i] - a[2][i],a[3][i] - a[2][i]});
                continue;
            }
            if(a[3][i] >= a[2][i] && a[3][i] >= a[1][i])
            {
                cnt3++;
                f[i] = 3;
                ans += a[3][i];
                q3.push({i,a[1][i] - a[3][i],a[2][i] - a[3][i]});
                continue;
            }
        }
        if(cnt1 <= n / 2 && cnt2 <= n / 2 && cnt3 <= n / 2)
        {
            cout << ans << "\n";
            continue;
        }
        if(cnt1 > n / 2)
        {
            while(cnt1 > n / 2)
            {
                cnt1--;
                node t = q1.top();
                q1.pop();
                if((t.l1 > t.l2 && cnt2 < n / 2) || cnt3 == n / 2)
                {
                    f[t.id] = 2;
                    cnt2++;
                    ans += t.l1;
                }
                else
                {
                    f[t.id] = 3;
                    cnt3++;
                    ans += t.l2;
                }
            }
        }
        else if(cnt2 > n / 2)
        {
            while(cnt2 > n / 2)
            {
                cnt2--;
                node t = q2.top();
                q2.pop();
                if((t.l1 > t.l2 && cnt1 < n / 2) || cnt3 == n / 2)
                {
                    f[t.id] = 1;
                    cnt1++;
                    ans += t.l1;
                }
                else
                {
                    f[t.id] = 3;
                    cnt3++;
                    ans += t.l2;
                }
            }
        }
        else if(cnt3 > n / 2)
        {
            while(cnt3 > n / 2)
            {
                cnt3--;
                node t = q3.top();
                q3.pop();
                if((t.l1 > t.l2 && cnt1 < n / 2) || cnt2 == n / 2)
                {
                    f[t.id] = 1;
                    cnt1++;
                    ans += t.l1;
                }
                else
                {
                    f[t.id] = 2;
                    cnt2++;
                    ans += t.l2;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
