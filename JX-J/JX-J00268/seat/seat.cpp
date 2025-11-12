#include<bits/stdc++.h>
using namespace std;
int n,m,lie,hang;
int a[15][15];
int ans;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
   for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]>a[1][1])
            {
                ans++;
            }
        }
    }
    ans++;
    if(ans%n==0)
    {
        lie=ans/n;
    }
    else
    {
        lie=ans/n+1;
    }
    if(lie%2==1)
    {
        if(ans%n==0)
        {
            hang=n;
        }
        else
        {
            hang=ans%n;
        }
    }
    else if(lie%2==0)
    {
        if(ans%n==0)
        {
            hang=1;
        }
        else
        {
            hang=n-(ans%n)+1;
        }
    }
    cout<<lie<<' '<<hang;
    return 0;
}
