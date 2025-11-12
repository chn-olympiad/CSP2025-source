#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e2 + 10;
int n,m,cnt = 0;
struct node
{
    int x;
    int i;
}a[N];

bool cmd(node x,node y)
{
    return x.x > y.x;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
        {
            cnt++;
            int pi = cnt;
            cin >> a[pi].x;
            a[pi].i = pi;
        }
    sort(a+1,a+1+cnt,cmd);
    int ci = 1;
    for(int i = 1;i <= m;i++)
    {
        if(i % 2 == 1)
        {
            for(int j = 1;j <= n;j++)
            {
                if(a[ci].i == 1)
                {
                    cout << i << " " << j;
                    return 0;
                }
                ci++;
            }
        }
        else
        {
            for(int j = n;j >= 1;j--)
            {
                if(a[ci].i == 1)
                {
                    cout << i << " " << j;
                    return 0;
                }
                ci++;
            }
        }
    }
    return 0;
}
