#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int T, n;

struct node
{
    int id, num;
};

bool cmp(node x, node y)
{
    return x.num < y.num;
}

int a[N][10];

int b[10];

node c[N];

int d[N];

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while(T--)
    {
        cin >> n;
        int ans = 0;
        memset(b, 0, sizeof(b));
        for(int i = 1;i <= n;i++)
        {
            int cur = 0;
            int cur1 = 1;
            for(int j = 1;j <= 3;j++)
            {
                scanf("%d", &a[i][j]);
                if(a[i][j] >= cur)
                {
                    cur = a[i][j];
                    cur1 = j;
                }
            }
            b[cur1]++;
            c[i].id = cur1;
            c[i].num = cur;
            ans += cur;
        }
        int curn = n / 2;
        if(b[1] > curn)
        {
            //cout << 3 << endl;
            int cur = 0;
            for(int i = 1;i <= n;i++)
            {
                if(c[i].id == 1)
                {
                    d[++cur] = min(c[i].num - a[i][2], c[i].num - a[i][3]);
                }
            }
            sort(d + 1,d + cur + 1);
            for(int i = 1;i <= b[1] - curn;i++)
            {
                ans -= d[i];
            }
        }
        else if(b[2] > curn)
        {
            //cout << 3 << endl;
            int cur = 0;
            for(int i = 1;i <= n;i++)
            {
                if(c[i].id == 2)
                {
                    d[++cur] = min(c[i].num - a[i][1], c[i].num - a[i][3]);
                }
            }
            sort(d + 1,d + cur + 1);
            for(int i = 1;i <= b[2] - curn;i++)
            {
                ans -= d[i];
            }
        }
        else if(b[3] > curn)
        {
            //cout << 3 << endl;
            int cur = 0;
            for(int i = 1;i <= n;i++)
            {
                if(c[i].id == 3)
                {
                    d[++cur] = min(c[i].num - a[i][2], c[i].num - a[i][1]);
                }
            }
            sort(d + 1,d + cur + 1);
            for(int i = 1;i <= b[3] - curn;i++)
            {
                ans -= d[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}