/*
    #include <bits/stdc++.h>
using namespace std;

struct node{
    int x, y, z;
}a[205];//i表示第i个人，xyz为对123的满意度

int n;

int f[5][205][205];// 表示第j个人选定第i个社团中并且社团的人数为k时所得分的最大值

int main()
{
    freopen("club1.in", "r", stdin);
    freopen("club1.out", "w", stdout);
    int t;
    cin >> t;

    while (t--)
    {

        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= 200; j++)
            {
                for (int k = 1; k <= 200; k++)
                {
                    f[i][j][k] = -1;
                }
            }
        }

        for (int i = 1; i <= 200; i++)
        {
            a[i].x = a[i].y = a[i].z = 0;
        }



        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].x >> a[i].y >> a[i].z;
        }

        int maxn = n / 2;//每个社团最多这么多人

        for (int i = 1; i <= n; i++)
        {
            f[1][i][1] = a[i].x;
            f[2][i][1] = a[i].y;
            f[3][i][1] = a[i].z;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= maxn; j++)
            {
                for (int k = 1; k <= 3; k++)
                {
                    if (k!=1)
                        f[1][i][j] = max(f[1][i-1][j-1], f[k][i-1][j]) + a[i].x;//转移方程
                    if (k!=2)
                        f[2][i][j] = max(f[2][i-1][j-1], f[k][i-1][j]) + a[i].y;//转移方程
                    if (k!=3)
                        f[3][i][j] = max(f[3][i-1][j-1], f[k][i-1][j]) + a[i].z;//转移方程
                }
            }
        }
        int maxx = -1;

        for (int i = 0; i <= maxn; i++)
        {
            for (int j = 0; j <= n - i-1; j++)
            {
                for (int k = 0; k <= n - j - i; k++)
                {
                    maxx = max(maxx, f[1][n][i] + f[2][n][j] + f[3][n][k]);
                }
            }
        }

       // cout << f[1][n][2] << " " << f[2][n][1] << " " <<  f[3][n][1];
        cout << maxx << endl;
    }
}

*/

#include <bits/stdc++.h>
using namespace std;

struct node{
    int x, y, z;
}a[205];//i表示第i个人，xyz为对123的满意度

int n;

int f[5][205][205];// 表示第j个人选定第i个社团中并且社团的人数为k时所得分的最大值

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;

    while (t--)
    {

        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= 200; j++)
            {
                for (int k = 1; k <= 200; k++)
                {
                    f[i][j][k] = -1;
                }
            }
        }

        for (int i = 1; i <= 200; i++)
        {
            a[i].x = a[i].y = a[i].z = 0;
        }



        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].x >> a[i].y >> a[i].z;
        }

        int maxn = n / 2;//每个社团最多这么多人

        for (int i = 1; i <= n; i++)
        {
            f[1][i][1] = a[i].x;
            f[2][i][1] = a[i].y;
            f[3][i][1] = a[i].z;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= maxn; j++)
            {
                for (int k = 1; k <= 3; k++)
                {
                    if (k!=1)
                    f[1][i][j] = max(f[1][i-1][j], f[k][i-1][j-1] + a[i].x);//转移方程
                    if (k!=2)
                    f[2][i][j] = max(f[2][i-1][j], f[k][i-1][j-1] + a[i].y);//转移方程
                    if (k!=3)
                    f[3][i][j] = max(f[3][i-1][j], f[k][i-1][j-1] + a[i].z);//转移方程
                }
            }
        }
        int maxx = -1;

        for (int i = 0; i <= maxn; i++)
        {
            for (int j = 0; j <= n - i-1; j++)
            {
                for (int k = 0; k <= n - j - i; k++)
                {
                    maxx = max(maxx, f[1][n][i] + f[2][n][j] + f[3][n][k]);
                }
            }
        }

        //cout << f[1][n][1] << " " << f[2][n][1] << " " <<  f[3][n][0];
        cout << maxx << endl;
    }
}
