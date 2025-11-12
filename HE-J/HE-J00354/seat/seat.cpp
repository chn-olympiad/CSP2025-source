#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[105],p=1,w=0;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[p];
            p++;
        }
    }
    int q=a[1];
    sort(a+1,a+p+1);
    w=p;
    for(int i=1;i<=m;i++)
    {
        if(i%2)
        {
            for(int j = 1;j<=n;j++)
            {
                w--;
                if(a[w]==q)
                {
                    cout<<i<<" "<<j;
                    break;
                }

            }
        }
        else
        {
            for(int j = n;j>=1;j--)
            {
                w--;
                if(a[w]==q)
                {
                    cout<<i<<" "<<j;
                    break;
                }
            }
        }
    }
    return 0;
}
