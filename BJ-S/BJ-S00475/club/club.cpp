#include <iostream>
#include <algorithm>
using namespace std;

int a[100005];
int b[100005];
int c[100005];

int cnta;
int cntb;
int cntc;

struct Node
{
    int x;
    int y;
    bool flag;
    int gx;
};

Node cla[100005];
Node clb[100005];
Node clc[100005];

bool cmp(Node x, Node y)
{
    return x.gx > y.gx;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        cnta = 0;
        cntb = 0;
        cntc = 0;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            cin >> b[i];
            cin >> c[i];
            if (a[i] >= b[i] && a[i] >= c[i])
            {
                cla[++cnta].y = a[i];
                cla[cnta].x = i;
                if (b[i] >= c[i])
                {
                    cla[cnta].flag = true;
                    cla[cnta].gx = a[i] - b[i];
                }
                else
                {
                    cla[cnta].flag = false;
                    cla[cnta].gx = a[i] - c[i];
                }
            }
            else if (b[i] >= a[i] && b[i] >= c[i])
            {
                clb[++cntb].y = b[i];
                clb[cntb].x = i;
                if (a[i] >= c[i])
                {
                    clb[cntb].flag = true;
                    clb[cntb].gx = b[i] - a[i];
                }
                else
                {
                    clb[cntb].flag = false;
                    clb[cntb].gx = b[i] - c[i];
                }
            }
            else
            {
                clc[++cntc].y = c[i];
                clc[cntc].x = i;
                if (a[i] >= b[i])
                {
                    clc[cntc].flag = true;
                    clc[cntc].gx = c[i] - a[i];
                }
                else
                {
                    clc[cntc].flag = false;
                    clc[cntc].gx = c[i] - b[i];
                }
            }
        }

        if (cnta > n / 2)
        {
            sort(cla + 1, cla + cnta + 1, cmp);
            for (int i = cnta; i > n / 2; i--)
            {
                if (cla[i].flag)
                {
                    cnta--;
                    clb[++cntb].y = b[cla[i].x];
                    clb[cntb].x = cla[i].x;
                }
                else
                {
                    cnta--;
                    clc[++cntc].y = c[cla[i].x];
                    clc[cntc].x = cla[i].x;
                }
            }
        }
        else if (cntb > n / 2)
        {
            sort(clb + 1, clb + cntb + 1, cmp);
            for (int i = cntb; i > n / 2; i--)
            {
                if (clb[i].flag)
                {
                    cntb--;
                    cla[++cnta].y = a[clb[i].x];
                    cla[cnta].x = clb[i].x;
                }
                else
                {
                    cnta--;
                    clc[++cntc].y = c[clb[i].x];
                    clc[cntc].x = clb[i].x;
                }
            }
        }
        else if (cntc > n / 2)
        {
            sort(clc + 1, clc + cntc + 1, cmp);
            for (int i = cntc; i > n / 2; i--)
            {
                if (clc[i].flag)
                {
                    cntc--;
                    cla[++cnta].y = a[clc[i].x];
                    cla[cnta].x = clc[i].x;
                }
                else
                {
                    cntc--;
                    clb[++cntb].y = b[clc[i].x];
                    clb[cntb].x = clc[i].x;
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= cnta; i++)
        {
            ans += cla[i].y;
        }
        for (int i = 1; i <= cntb; i++)
        {
            ans += clb[i].y;
        }
        for (int i = 1; i <= cntc; i++)
        {
            ans += clc[i].y;
        }
        cout << ans << endl;
    }
    return 0;
}
