#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],p,b[105][105],t=1;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","W",stdout);
    cin>>n>>m;
    cin>>a[1];
    p=a[1];
    for(int i=2;i<=n*m;i++)
        cin>>a[i];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=m;i++)
    {
        if(i%2!=0)
        {
            for(int j=1;j<=n;j++)
            {
                b[j][i]=a[t];
                t++;
                if(b[j][i]==p)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }

            }
        }
        else
        {
            for(int j=n;j>=1;j--)
            {
                b[j][i]=a[t];
                t++;
                if(b[j][i]==p)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }

            }
        }
    }
    return 0;
}
