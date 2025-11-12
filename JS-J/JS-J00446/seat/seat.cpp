#include <bits/stdc++.h>
using namespace std;
int n,m,c,r;
int a[110];
int f[20][20];
int k,cnt;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    k=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=m;i++)
    {
        if(i%2!=0)
        {
            for(int j=1;j<=n;j++)
            {
                cnt++;
                f[j][i]=a[n*m-cnt+1];
            }
        }
        if(i%2==0)
        {

            for(int j=n;j>=1;j--)
            {
                cnt++;
                f[j][i]=a[n*m-cnt+1];
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(f[i][j]==k)
            {
                cout<<j<<" "<<i;
            }
        }
    }

    return 0;
}
