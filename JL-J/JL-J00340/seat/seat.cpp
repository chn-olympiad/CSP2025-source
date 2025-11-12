#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001],i,j;
int main()
{
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin>>a[j];
        }
    }
    sort(a+1,a+j+1);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cout<<a[j]<<endl;
        }
    }
    return 0;
}
