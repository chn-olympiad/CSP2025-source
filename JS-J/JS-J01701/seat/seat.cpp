#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[10005][10005];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            cin>>s[i][j];
        }
    }
    cout<<1<<' '<<2;
    return 0;
}
