#include<bits/stdc++.h>
using namespace std;
int a[100005][6];
int c[400005];
int b[10];
int p[100005];
int u[100005];
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    long long t, n, maxx= 0;
    cin >> t;
    for(int i = 0; i < t;i++)
    {
        maxx = 0;
        cin >> n;
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                cin >> a[j][k];
            }
        }
        for(int j = 0; j < n; j++)
        {
            int s = max(max(a[j][0], a[j][1]), a[j][2]);
            a[j][0] = s - a[j][0];
            a[j][1] = s - a[j][1];
            a[j][2] = s - a[j][2];
            maxx += s;
        }
        int d = n / 2, e = n, g = 0, v = 0;
        for(int j = 0; j < 3; j++)
        {
            int f = 0;
            int q = 0;
            int o = 0;
            for(int k = 0; k < n; k++)
            {
                if(a[k][j] == 0)
                {
                    f++;
                    p[g] = k;
                    g++;
                    q++;
                    u[v] = k;
                    v++;
                    o++;
                }
            }
            if(f <= d)
            {
                e-=f;
                g -= q;
            }
            else
            {
                e -= d;
                v-=o;
            }
        }
        int h = 0;
        for(int i = 0; i < v; i++)
        {
            for(int j = 0; j < g; j++)
            {
                if(p[j] == u[i])
                {
                    p[j] = -1;
                    e-=1;
                }
            }
        }
        for(int j= 0; j < g; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                if(p[j] == -1)
                {
                    break;
                }
                if(a[p[j]][k] != 0 && a[p[j]][k] != -1)
                {
                    c[h] = a[p[j]][k];
                    h++;
                    a[p[j]][k] = -1;
                }
            }
        }
        sort(c, c+h);
        for(int j = 0; j < e; j++)
        {
            maxx-=c[j];
        }
        b[i] = maxx;
    }
    for(int i = 0; i < t; i++)
    {
        cout << b[i] <<endl;
    }
    return 0;
}
