#include<bits/stdc++.h>
using namespace std;
int a[1000000], b[1000000], c[1000000];
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        int n, s2 = 0, s3 = 0;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i] >> b[i] >> c[i];
            if(b[i] == 0) s2++;
            if(c[i] == 0) s3++;
        }
        if(s2 == n && s3 == n)
        {
            sort(a + 1, a + n + 1);
            long long s = 0;
            for(int i = n; i >= n / 2 + 1; i--)
            {
                s += a[i];
            }
            cout << s << endl;
            return 0;
        }
    }
    return 0;
}
