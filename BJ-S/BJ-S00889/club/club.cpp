#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
long long n, T;
long long a[N][5];
long long c1[N], c2[N], c3[N];
long long cnt1 = 0, cnt2 = 0, cnt3 = 0;
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while(T -- )
    {
        priority_queue<pair<long long, long long>> p1, p2, p3;
        long long ans = 0;
        cnt1 = 0, cnt2 = 0, cnt3 = 0;
        memset(a, 0, sizeof a);
        cin >> n;
        for(int i = 1; i <= n; i ++ )
        {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3])
            {
                p1.push({-a[i][1] + max(a[i][2], a[i][3]), i});
                ans += a[i][1];
                cnt1 ++ ;
            }else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3])
            {
                p2.push({-a[i][2] + max(a[i][1], a[i][3]), i});
                ans += a[i][2];
                cnt2 ++ ;
            }else
            {
                p3.push({-a[i][3] + max(a[i][1], a[i][2]), i});
                ans += a[i][3];
                cnt3 ++ ;
            }
        }
        while(cnt1 > n / 2)
        {
            cnt1 -- ;
            auto t = p1.top();
            p1.pop();
            ans += t.first;
        }
        while(cnt2 > n / 2)
        {
            cnt2 -- ;
            auto t = p2.top();
            p2.pop();
            ans += t.first;
        }
        while(cnt3 > n / 2)
        {
            cnt3 -- ;
            auto t = p3.top();
            p3.pop();
            ans += t.first;
        }
        cout << ans << endl;
    }
    return 0;
}
