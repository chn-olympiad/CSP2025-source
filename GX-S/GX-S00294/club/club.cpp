#include <bits/stdc++.h>
using namespace std;
int t,n,a[5][5],x1,x2,x3,sum;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    for (int i = 1;i <= t;i++)
    {
        cin >> n;
        for (int j = 1;j <= n;j++)
        {
            cin >> a[j][1] >> a[j][2] >> a[j][3];
            int y = max(a[j][1],max(a[j][2],a[j][3]));
            if (a[j][1] == y && x1 < n)
            {
                x1++;
                sum+=a[j][1];
            }
            else if (a[j][1] == y && x1 >= n)
            {
                if (a[j][2] > a[j][3])
                {
                    x2++;
                    sum+=a[j][2];
                }
                else
                {
                    x3++;
                    sum+=a[j][3];
                }
            }
            if (a[j][2] == y && x2 < n)
            {
                x2++;
                sum+=a[j][2];
            }
            else if (a[j][2] == y && x2 >= n)
            {
                if (a[j][1] > a[j][3])
                {
                    x1++;
                    sum+=a[j][1];
                }
                else
                {
                    x3++;
                    sum+=a[j][3];
                }
            }
            if (a[j][3] == y && x3 < n)
            {
                x3++;
                sum+=a[j][3];
            }
            else if (a[j][3] == y && x3 >= n)
            {
                if (a[j][2] > a[j][1])
                {
                    x2++;
                    sum+=a[j][2];
                }
                else
                {
                    x1++;
                    sum+=a[j][1];
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}
