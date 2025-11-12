# include <bits/stdc++.h>
using namespace std;
int t;
int a[100100][8];
//int b[100100], c[100100], d[100100];
struct node
{
    int x, y, z;
}b[100100], c[100100], d[100100], clu[100100][8];

bool cmp(node q, node p)
{

    return a[q.y][q.z] - max(a[q.y][(q.z + 1) % 3], a[q.y][(q.z + 2) % 3]) < a[p.y][p.z] - max(a[p.y][(p.z + 1) % 3], a[p.y][(p.z + 2) % 3]);
    //return q.x < p.x;
}

long long maxx[8];
int o[8] = {1, 1, 1, 1, 1, 1, 1, 1};
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        memset(d, 0, sizeof(d));
        memset(maxx, 0, sizeof(maxx));
        memset(clu, 0, sizeof(clu));
        o[1] = 1; o[2] = 1; o[3] = 1;
        int n;
        cin >> n;

        for (int i = 1; i <= n; i ++)
        {
            scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
            //cin >> a[i][1] >> a[i][2] >> a[i][3];
            if (a[i][1] == max(max(a[i][1], a[i][2]), a[i][3]))
            {
                b[o[1]].z = 1;
                b[o[1]].y = i;
                b[o[1]++].x = a[i][1];
                maxx[1] += a[i][1];
                continue;
            }
            if (a[i][2] == max(max(a[i][1], a[i][2]), a[i][3]))
            {
                c[o[2]].z = 2;
                c[o[2]].y = i;
                c[o[2]++].x = a[i][2];
                maxx[2] += a[i][2];
                continue;
            }
            if (a[i][3] == max(max(a[i][1], a[i][2]), a[i][3]))
            {
                d[o[3]].z = 3;
                d[o[3]].y = i;
                d[o[3]++].x = a[i][3];
                maxx[3] += a[i][3];
                continue;
            }
        }
        o[1]--;o[2]--;o[3]--;
        sort(b+1, b+o[1]+1, cmp);
        sort(c+1, c+o[2]+1, cmp);
        sort(d+1, d+o[3]+1, cmp);

        for (int i = 1; i <= o[1]; i ++)
        {
            clu[i][1].x = b[i].x;
            clu[i][1].y = b[i].y;
            clu[i][1].z = b[i].z;
        }
        for (int i = 1; i <= o[2]; i ++)
        {
            clu[i][2].x = c[i].x;
            clu[i][2].y = c[i].y;
            clu[i][2].z = c[i].z;
        }
        for (int i = 1; i <= o[3]; i ++)
        {
            clu[i][3].x = d[i].x;
            clu[i][3].y = d[i].y;
            clu[i][3].z = d[i].z;
        }
        if (max(max(o[1], o[2]), o[3]) <= n / 2)
        {
            cout << maxx[1] + maxx[2] + maxx[3] << endl;
        }
        else
        {
            //cout << o[1] << " " << o[2] << " " << o[3] << endl;
            int maxn = 0, t = 0;
            for (int i = 1; i <= 3; i ++)
            {
                if (o[i] > maxn)
                {
                    maxn = o[i];
                    t = i;
                }
            }
            //cout << t << " ";
            int q = o[t];
            for (int i = 1; i <= q - n/2; i ++)
            {
                //cout << q - n/2 + 1 << " ";
                //cout << clu[i][t].y << " " << t << " " << a[clu[i][t].y][t] << " ";
                if (a[clu[i][t].y][(t+1)%3] > a[clu[i][t].y][(t+2)%3])
                {
                    maxx[t] -= a[clu[i][t].y][t];
                    maxx[(t+1)%3] += a[clu[i][t].y][(t+1)%3];
                    clu[o[(t+1)%3]][(t+1)%3].y = clu[i][t].y;
                    clu[o[(t+1)%3]++][(t+1)%3].x = clu[i][t].x;
                    o[t]--;

                }
                else
                {
                    maxx[t] -= a[clu[i][t].y][t];
                    maxx[(t+2)%3] += a[clu[i][t].y][(t+2)%3];
                    clu[o[(t+2)%3]][(t+2)%3].y = clu[i][t].y;
                    clu[o[(t+2)%3]++][(t+2)%3].x = clu[i][t].x;
                    o[t]--;

                }
            }
            //cout << o[1] << " " << o[2] << " " << o[3] << endl;
            cout << maxx[1] + maxx[2] + maxx[3] << endl;
        }
    }
    return 0;
}
