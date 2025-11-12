#include<bits/stdc++.h>
using namespace std;
int a[110][110],s[110];
int main()
{
    freopen("seat.in","w",stdin);
    freopen("seat.out","r",stdout);
    int m,n,i,j,k;
    cin>>n>>m;
    if(m==1&&n==1)
        cout<<m<<" "<<n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
            s[i]++;
    for(int k=110;k>=1;k--)
    {
        if(s[i]!=0)
        {
            if(k==a[1][1])
            {
                cout<<i+k<<j+k;
            }

        }
    }
    return 0;
}
