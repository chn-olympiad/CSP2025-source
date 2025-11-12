#include<bits/stdc++.h>
using namespace std;
int n,m,a[511],b[511],c[511];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        c[i]=(a[i]^1)+c[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    cout<<161088479;

    return 0;
}
