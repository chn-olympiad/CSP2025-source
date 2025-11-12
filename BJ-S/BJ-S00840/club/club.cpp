#include<bits/stdc++.h>
using namespace std;
long long t, n, s[100005][3], ans, b[100005];
struct node
{
    long long x, y, z;
}a[100005];
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(long long i = 1;i <= n;i++)
        {
            cin >> a[i].x >> a[i].y >> a[i].z;
            ans += max(max(a[i].x, a[i].y), a[i].z);
            if(a[i].x >= a[i].y && a[i].x >= a[i].z)
            {
                s[++s[0][0]][0] = i;
            }
            else if(a[i].x <= a[i].y && a[i].y >= a[i].z)
            {
                s[++s[0][1]][1] = i;
            }
            else if(a[i].x <= a[i].z && a[i].y <= a[i].z)
            {
                s[++s[0][2]][2] = i;
            }
        }
        if(s[0][0] > (n / 2))
        {
            for(long long i = 1;i <= s[0][0];i++)
            {
                b[i] = a[s[i][0]].x - max(a[s[i][0]].y,
                                          a[s[i][0]].z);
            }
            sort(b + 1, b + s[0][0] + 1);
            for(long long i = 1;i <= s[0][0] - (n / 2);i++)
            {
                ans -= b[i];
            }
        }
        if(s[0][1] > (n / 2))
        {
            for(long long i = 1;i <= s[0][1];i++)
            {
                b[i] = a[s[i][1]].y - max(a[s[i][1]].x,
                                          a[s[i][1]].z);
            }
            sort(b + 1, b + s[0][1] + 1);
            for(long long i = 1;i <= s[0][1] - (n / 2);i++)
            {
                ans -= b[i];
            }
        }
        if(s[0][2] > (n / 2))
        {
            for(long long i = 1;i <= s[0][2];i++)
            {
                b[i] = a[s[i][2]].z - max(a[s[i][2]].y,
                                          a[s[i][2]].x);
            }
            sort(b + 1, b + s[0][2] + 1);
            for(long long i = 1;i <= s[0][2] - (n / 2);i++)
            {
                ans -= b[i];
            }
        }
        cout << ans << endl;
        for(long long i = 0;i <= n;i++)
        {
            s[i][0] = 0;
            s[i][1] = 0;
            s[i][2] = 0;
            b[i] = 0;
        }
        ans = 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
