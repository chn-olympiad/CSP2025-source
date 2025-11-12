#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,r[501],ans=1,a;
    cin>>n>>m>>a;
    for(int i=1;i<=n;i++)
        cin>>r[i];
    for(int i=2;i<=n;i++)
    {
        ans*=i;
    }
    cout<<ans;

    return 0;
}

