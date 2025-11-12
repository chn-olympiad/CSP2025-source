#include <bits/stdc++.h>
using namespace std;
int n,m,a[105][105],f[105],x,y=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>f[i];
        x=f[1];
    }
    if(n*m==1)
    {
        cout<<f[1];
        return 0;
    }
    sort(f+1,f+n*m+1);
    reverse(f+1,f+n*m+1);
    for(int i=1;i<=m;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<=n;j++)
            {
                a[j][i]=f[y];
                y++;
                if(a[j][i]==x)
                {
                    cout<<1<<endl;
                    cout<<i<<" "<<j;
                    return 0;
                }
             }
         }
         else
         {
            for(int j=n;j>=1;j--)
            {
                a[j][i]=f[y];
                y++;
                if(a[j][i]==x)
                {
                    cout<<2<<endl;
                    cout<<i<<" "<<j;
                    return 0;
                }
             }
         }
    }
    return 0;
}
