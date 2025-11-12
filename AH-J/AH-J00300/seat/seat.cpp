#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int n,m,a1;
int main(){
    freopen ("seat.in","r",stdin);
    freopen ("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i];
        }
    }
    a1=a[1];
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if(a[i][j]==a1)
            {
                cout<<i<<' '<<j;
            }
        }
    }
    return 0;
}
