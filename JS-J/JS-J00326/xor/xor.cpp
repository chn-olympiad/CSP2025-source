#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[500010];
int ans = 0;
int n , m;
int cnt = 0;
struct timeo
{
    int x = 0 , y = 0;
}b[500010];

void dfs(int i , int ant)
{
    //cout << i << " " << ant << endl;
    if(i >= cnt)
    {
        ans = max(ans , ant);
        return;
    }
    int t = i;
    i++;
    for(i;i <= cnt;i++)
    {
        if(b[i].x <= b[t].y) continue;
        dfs(i , ant + 1);
    }
    return;
}

bool cmp(timeo x , timeo y)
{
    if(x.x != y.x) return x.x < y.x;
    return x.y < y.y;
}

signed main()
{
    //ctrl + s!!!!!!
    freopen("xor.in" , "r" , stdin);
    freopen("xor.out" , "w" , stdout);
    //x != 3;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++)
        for(int j = i;j <= n;j++)
        {
            int sum = a[i];
            for(int k = i + 1;k <= j;k++)
                sum = sum ^ a[k];
            if(sum == m)
            {
                b[++cnt].x = i;
                b[cnt].y = j;
                //cout << b[cnt].x << " " << b[cnt].y << endl;
            }
        }
    sort(b + 1 , b + cnt + 1 , cmp);
    dfs(0 , 0);
    cout << ans << endl;
    return 0;
}
