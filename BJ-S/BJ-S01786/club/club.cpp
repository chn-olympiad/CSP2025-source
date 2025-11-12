#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], b[N], c[N];
int c1[N], c2[N];
int a3[N], b3[N], c3[N], sum[N];
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t, n, aa, bb, cc, s, ans = 0, cnt;
    cin >> t;
    while(t--)
    {
        ans = 0, cnt = 0, aa = 0, bb = 0, cc = 0;
        cin >> n;
        s = n / 2;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i] >> b[i] >> c[i];
            if(a[i] < b[i] && c[i] < b[i] && a[i] < c[i])
            {
                c1[i] = b[i];
                bb++;
                b3[i] = b[i];
                c2[i] = c[i];
            }
            else if(a[i] < b[i] && c[i] < b[i] && c[i] < a[i])
            {
                c1[i] = b[i];
                bb++;
                b3[i] = b[i];
                c2[i] = a[i];
            }
            else if(b[i] < a[i] && c[i] < a[i] && b[i] < c[i])
            {
                c1[i] = a[i];
                aa++;
                a3[i] = a[i];
                c2[i] = c[i];
            }
            else if(b[i] < a[i] && c[i] < a[i] && c[i] < b[i])
            {
                c1[i] = a[i];
                aa++;
                a3[i] = a[i];
                c2[i] = b[i];
            }
            else if(b[i] < c[i] && a[i] < c[i] && a[i] < b[i])
            {
                c1[i] = c[i];
                cc++;
                c3[i] = c[i];
                c2[i] = b[i];
            }
            else if(b[i] < c[i] && a[i] < c[i] && b[i] < a[i])
            {
                c1[i] = c[i];
                cc++;
                c3[i] = c[i];
                c2[i] = a[i];
            }
            else if(a[i] == b[i] && c[i] < a[i])
            {
                c1[i] = a[i];
                aa++;
                a3[i] = a[i];
                c2[i] = a[i];
            }
            else if(a[i] == b[i] && a[i] < c[i])
            {
                c1[i] = c[i];
                cc++;
                c3[i] = c[i];
                c2[i] = a[i];
            }
            else if(a[i] == c[i] && b[i] < a[i])
            {
                c1[i] = a[i];
                aa++;
                a3[i] = a[i];
                c2[i] = a[i];
            }
            else if(a[i] == c[i] && a[i] < b[i])
            {
                c1[i] = b[i];
                bb++;
                b3[i] = b[i];
                c2[i] = a[i];
            }
            else if(b[i] == c[i] && a[i] < b[i])
            {
                c1[i] = b[i];
                bb++;
                b3[i] = b[i];
                c2[i] = b[i];
            }
            else if(b[i] == c[i] && b[i] < a[i])
            {
                c1[i] = a[i];
                aa++;
                a3[i] = a[i];
                c2[i] = b[i];
            }
        }
        if(aa <= s && bb <= s && cc <= s)
        {
            for(int i = 1; i <= n; i++)
            {
                ans += c1[i];
            }
            cout << ans << endl;
        }
        else
        {
            while(aa > s)
            {
                aa--;
                for(int i = 1; i <= n; i++)
                {
                    sum[i] = a3[i] - c2[i];
                }
                for(int i = 1; i < n; i++)
                {
                    if(sum[i] <= sum[i + 1]) cnt = i;
                    else cnt = i + 1;
                }
                c1[cnt] = c2[cnt];
            }
            while(bb > s)
            {
                bb--;
                for(int i = 1; i <= n; i++)
                {
                    sum[i] = b3[i] - c2[i];
                }
                for(int i = 1; i < n; i++)
                {
                    if(sum[i] <= sum[i + 1]) cnt = i;
                    else cnt = i + 1;
                }
                c1[cnt] = c2[cnt];
            }
            while(cc > s)
            {
                cc--;
                for(int i = 1; i <= n; i++)
                {
                    sum[i] = c3[i] - c2[i];
                }
                for(int i = 1; i < n; i++)
                {
                    if(sum[i] <= sum[i + 1]) cnt = i;
                    else cnt = i + 1;
                }
                c1[cnt] = c2[cnt];
            }
            for(int i = 1; i <= n; i++)
            {
                ans += c1[i];
            }
            cout << ans << endl;
        }
    }
    return 0;
}
