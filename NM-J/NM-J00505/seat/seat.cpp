#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp(int x, int y)
{
    return x > y;
}
int n, m, al, rrr, c[105], idx, a[15][15], cnt = 1;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    al = n * m;
    for(int i = 1;i <= al;i++) cin >> c[i];
    rrr = c[1];
    sort(c + 1, c + al + 1, cmp);
    for(int i = 1;i <= al;i++)
    {
        if(c[i] == rrr)
        {
            idx = i;
            break;
        }
    }
    for(int i = 1;i <= n;)
    {
        for(int j = 1;j <= m;)
        {
            if(cnt == idx)
            {
                cout << j << ' ' << i;
                return 0;
            }
            if(j % 2 == 1)
            {
                if(i == n)
                {
                    j++;
                    cnt++;
                }
                else
                {
                    i++;
                    cnt++;
                }
            }
            else
            {
                if(i == 1)
                {
                    j++;
                    cnt++;
                }
                else
                {
                    i--;
                    cnt++;
                }
            }
        }
    }
}
