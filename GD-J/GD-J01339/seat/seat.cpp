#include <bits/stdc++.h>
using namespace std;
long long a[15][15],R,n,m,v[15][15],b[110],zong;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            cin >> a[i][j];
            b[a[i][j]]++;
        }
    }
    R=a[1][1],zong=100;
    for (int i=1;i<=m;i++)
    {
        if (i%2==1)
        {
            for (int j=1;j<=n;j++)
            {
                int geshu=0;
                while (!geshu)
                {
                    if (b[zong])
                    {
                        geshu++;
                        v[j][i]=zong;
                    }
                    zong--;
                }
            }
        }
        else
        {
            for (int j=n;1<=j;j--)
            {
                int geshu=0;
                while (!geshu)
                {
                    if (b[zong])
                    {
                        geshu++;
                        v[j][i]=zong;
                    }
                    zong--;
                }
            }
       }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (v[i][j]==R)
            {
                cout << j << " " << i;
                return 0;
            }
        }
    }
}

