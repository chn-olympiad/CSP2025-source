#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    long long a[1005];
    long long p[1005][1005];
    cin >>n >>m;
    int ans = 0;//ming
    int sum = n*m;//renshu
    int pd = 0;
    int mpd=0;
    for (int i = 0;i<sum;i++)
    {
        cin >>a[i];
    }
    for (int i = 1;i<= sum;i++)
    {
        if(a[0] <a[i])
        {
            ans++;
        }
    }
     for (int i = 1;i<=m;i++)
    {
        if(pd ==0)//1kaishi
        {
            for (int j = 1;j<=n;j++)
            {
                pd = 1;
                mpd++;
                if(mpd == ans+1)
                {
                    cout << i <<" "<<j;
                    return 0;
                }
            }
        }
        else if(pd == 1)
        {
            for (int j = n;j>=1;j--)
            {
                pd = 0;
                mpd++;
                if(mpd == ans+1)
                {
                    cout << i <<" "<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
