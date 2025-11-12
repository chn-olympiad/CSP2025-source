//GZ-S00443 华麟 郭一菲
#include <bits/stdc++.h>
using namespace std;
long long  ans = 0, n, q;
struct oi{
    string x, y;
}a[10005];
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 1; i <= q; i++)
    {
        string c, d;
        cin >> c >> d;
        int cnt = 0;
        for (int i = 0; i < c.size(); i++)
        {
            for (int j = 1; j <= n; j++)
            {

                if (c[i] == a[j].x[0])
                {
                    int flag = true;

                    for (int k = i; k <= i + a[j].x.size() - 1; k++)
                    {
                        if (c[k] != a[j].x[k - i])flag = false;
                    }

                    if (flag == true)
                    {
                        for (int i1 = 0; i1 < d.size(); i1++)
                        {
                            for (int j1 = 1; j1 <= n; j1++)
                                {
                                    if (d[i1] == a[j].y[0])
                                    {
                                        for (int k1 =0; k1 <= a[j].x.size() - 1; k1++)
                                        {
                                            if (d[k1 + i1] != a[j].y[k1])flag = false;
                                        }

                                    }
                                }

                        }
                        if (flag == true){
                                        cnt++;
                                        continue;
                                    }
                    }

                }
                if (c[i] == a[j].y[0])
                {
                    int flag = true;
                    for (int k = i; k <= i + a[j].y.size() - 1; k++)
                    {
                        if (c[k] != a[j].y[k - i])flag = false;
                    }
                    if (flag == true){
                        for (int i1 = 0; i1 < d.size(); i1++)
                        {
                            for (int j1 = 1; j1 <= n; j1++)
                            {
                                if (d[i1] == a[j].x[0])
                                {
                                    for (int k1 = 0; k1 <= a[j].y.size() - 1; k1++)
                                    {
                                        if (d[i1 + k1] != a[j].x[ k1])flag = false;
                                    }

                                }
                            }


                        }
                    }
                    if (flag == true)
                                    {
                                        cnt++;
                                        continue;
                                    }

                }
            }
        }
        cout << cnt;
    }

    return 0;
}

