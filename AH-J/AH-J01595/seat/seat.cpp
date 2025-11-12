#include<bits/stdc++.h>
using namespace std;
int n,m,k,venti,a[5943],mp[500][500];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    //cin
    cin>>n>>m;
    k=n*m;
    for(int i=1;i<=k;i++)
    {
        cin>>a[i];
    }
    venti=a[1];
    sort(a+1,a+k+1);

    //make map
    for(int j=1;j<=n;j++)
    {
        if(j%2!=0)
        {
            for(int i=1;i<=m;i++)
            {
                mp[i][j]=a[k];
                k--;
            }
        }
        else
        {
            for(int i=m;i>0;i--)
            {
                mp[i][j]=a[k];
                k--;
            }
        }
    }

    //cout
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mp[i][j]==venti)
            {
                cout<<j<<' '<<i;
                break;
            }
        }
    }
    //may one hundred
    return 0;
}
