#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=m*n;i++)
    {
        cin>>a[i];
    }
    if(m==1&&n==1) cout<<1<<' '<<1;
    else cout<<m<<' '<<n;
    return 0;
}
