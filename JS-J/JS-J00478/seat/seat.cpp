#include <bits/stdc++.h>
using namespace std;

int n,m,a[110][110],s[100010];

int xiaoa = 0;

bool cmp(int x,int y)
{
    return x > y;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n * m;i++)
    {
        cin >> s[i];
    }
    xiaoa = s[1];
    sort(s + 1,s + n * m + 1,cmp);
    int dx = 1,dy = 1;
    int cnt = 0;
    while(dx <= n && dx >= 1 && dy >= 1 && dy <= m)
    {
        a[dx][dy] = s[++cnt];
        if(s[cnt] == xiaoa)
        {
            cout << dx << " " << dy << "\n";
            break;
        }
        if(dx == n && dy == m)
        {
            break;
        }
        if(dx % 2)
        {
            if(dy < n)
            {
                dy++;
            }
            else
            {
                dx++;
            }
        }
        else
        {
            if(dy > 1)
            {
                dy--;
            }
            else
            {
                dx++;
            }
        }
    }
    return 0;
}
