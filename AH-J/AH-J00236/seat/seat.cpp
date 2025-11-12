#include<bits/stdc++.h>
using namespace std;
int n,m,c;
int a[1005];
int mp[105][105];
int main(void)
{
    //seat
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int t=a[1];
    sort(a+1,a+n*m+1);
    c=n*m;
    for(int j=1;j<=m;j++)
    {
        if(j%2==1)
        {
            for(int i=1;i<=n;i++)
            {
                mp[i][j]=a[c];
                c--;
            }
        }

        else
        {
            for(int i=n;i>=1;i--)
            {
                mp[i][j]=a[c];
                c--;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mp[i][j]==t)
            {
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
