#include <bits/stdc++.h>
using namespace std;
int s[7000][7000],a[7000];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int R=a[1];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i][j]==R)
            {
                cout<<i<<" "<<j;
                break;
            }
        }
    }
    return 0;
}
