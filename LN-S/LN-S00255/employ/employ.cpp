#include<bits/stdc++.h>
using namespace std;
int a[500];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,s=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        s*=i;
    }
    cout<<s%998244353;
    return 0;
}
