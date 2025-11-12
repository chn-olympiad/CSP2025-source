#include <bits/stdc++.h>
using namespace std;
int s[1000],p[1000];
long long ans=1;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin >>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin >>s[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin >>p[i];
    }
    for(int i=1;i<=n;i++)
    {
        ans=(ans*i)%998244353;
    }
    cout <<ans;
    return 0;
}
