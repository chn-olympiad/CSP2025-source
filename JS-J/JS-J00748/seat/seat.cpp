#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 5;
int n,m;
int a[maxn];
int dx[] = {0,1,0,1};
int dy[] = {1,0,-1,0};
bool cmp(int p,int q)
{
    return p > q;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n * m; i++)
    {
        cin >> a[i];
    }
    int k = a[1];
    sort(a + 1,a + n*m + 1,cmp);
    int rk;
    for(int i = 1;i <= n * m;i++)
    {
        if(a[i] == k)
        {
            rk = i;
            break;
        }
    }
    // cout << rk << endl;
    int x = 1,y = 1,now = 1,d = 0;
    while(true)
    {
        if(now == rk) 
        {
            cout << x << ' ' << y << endl;
            return 0;
        }
        now++;
        int tx = x + dx[d],ty = y + dy[d];
        if(tx >= 1 && tx <= n && ty >= 1 && ty <= m)
        {
            x = tx;
            y = ty;
        }
        else
        {
            d = (d + 1) % 4;
            x += dx[d];
            y += dy[d];
        }
    }
    return 0;
}