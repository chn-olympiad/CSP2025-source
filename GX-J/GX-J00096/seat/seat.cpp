#include <bits/stdc++.h>
using namespace std;
int seat[11][11];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n, m, now_n, now_m, fang, a[121] = {};
    cin >> n >>m;
    int num = n*m;
    for(int i=1; i <= num; i++)
    {
        cin >> a[i];
    }
    int r = a[1];
    sort(a+1, a+num+1);
    if(m%2==0)
    {
        now_n = 1, now_m = m;
        fang = 0;
    }
    else
    {
        now_n = n, now_m = m;
        fang = 1;
    }
    for(int i=1; i <= num; i++)
    {
        seat[now_n][now_m] = a[i];
        if(now_n==1 && now_m==1)
        {
            break;
        }
        if(now_m%2!=0 && now_n == n)
        {
            fang = 1;
        }
        if(now_m%2 == 0 && now_n != 1)
        {
            fang = 0;
        }
        if(fang==0 && now_n != n)
        {
            now_n++;
        }
        else if(fang==1 && now_n != 1)
        {
            now_n--;
        }
        else
        {
            now_m--;
            fang = 0;
        }
    }
    for(int i=1; i <= n; i++)
    {
        for(int j=1; j <= m; i++)
        {
            if(seat[i][j] == r)
            {
                cout << i << " " <<j;
                break;
            }
        }
    }
    return 0;
}
