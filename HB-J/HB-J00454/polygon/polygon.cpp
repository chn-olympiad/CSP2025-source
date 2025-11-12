#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[n+5];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int s=0;
    for(int i=1;i<=n-2;i++)
    {
        s+=i;
    }
    cout<<s%988%244%353;
    return 0;
}
