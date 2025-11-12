#include <bits/stdc++.h>
using namespace std;
int n,a[5005],sum,maxx=-1;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        maxx=max(maxx,a[i]);
    }
    if(sum>(maxx*2)) cout<<1<<endl;
    else cout<<0<<endl;
    return 0;
}
