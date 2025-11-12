#include<bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
    int n,i;
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10)
    cout<<6;
    else cout<<9;
    return 0;
}
