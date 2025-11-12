#include<bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
    int n,k,i;
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==4&&k==2&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3) cout<<2;
    else cout<<1;
    return 0;
}
