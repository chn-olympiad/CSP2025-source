#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int a[100005],b[1005][1005],t=0,s=0,p;
    cin>>n>>m;
    for (int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        p=a[1];
    }
    for (int i=1;i<=n*m;i++)
    {
        for (int j=1;j<=i;j++)
        {
            if (a[i]<a[i+1])
            {
                t=a[i];
                a[i]=a[i+1];
                a[i+1]=t;
            }
        }
    }
    for (int i=1;i<=m;i++)
    {
        if (i%2!=0)
        {
            for(int j=1;j<=n;j++)
            {
                s++;
                b[i][j]=a[s];
                if (b[i][j]==p)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
        else
        {
            for (int j=n;j>=1;j--)
            {
                s++;
                b[i][j]=a[s];
                if (b[i][j]==p)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
