#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int t,ans = 0;
    cin >> t;
    while(t--)
    {
        int h = 0,g = 0;
        int n;
        cin >> n;
        int a[N] = {},b[N] = {},c[N] = {};
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i] >> b[i] >> c[i];
        }
        for(int i = 1;i <= n;i++)
        {
            if(c[i] != 0)
            {
                h = 0;
                break;
            }
        }
        for(int i = 1;i <= n;i++)
        {
            if(b[i] != 0)
            {
                g = 0;
                break;
            }
        }
        if(h)
        {
            if(g)
            {
                sort(a + 1,a + n + 1);
                for(int i = n;i >= n / 2 + 1;i--)
                {
                    ans += a[i];
                }
            }
        }
        cout << ans << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
