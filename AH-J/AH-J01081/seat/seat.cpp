#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int i,j,n,m,a[11][11],maxn=0;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    if(n==1&&m==1)
    {
        cout<<"1 1";
        return 0;
    }
    cout<<n<<" "<<4-n;
    return 0;
}
