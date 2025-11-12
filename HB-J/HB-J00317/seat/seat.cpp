#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define int long long
const int N = 1e4+7;

struct node{
    int score;
    int id;
}a[N];

int n, m;

bool cmp(node x, node y)
{
    return x.score > y.score;
}

signed main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n*m; i++)
    {
        cin >> a[i].score;
        a[i].id = i;
    }
    sort(a+1, a+n*m+1, cmp);
    int now = 1;
    bool flag = 1;
    for (int i = 1; i <= m; i++)
    {
        if (flag)
        {
            for (int j = 1; j <= n;j++)
            {
                if (a[now].id == 1)
                {
                    cout << i << ' ' << j;
                    return 0;
                }
                now++;
            }
        }
        else
        {
            for (int j = n; j >= 1;j--)
            {
                if (a[now].id == 1)
                {
                    cout << i << ' ' << j;
                    return 0;
                }
                now++;
            }
        }
        flag = !flag;
    }


    return 0;
}
