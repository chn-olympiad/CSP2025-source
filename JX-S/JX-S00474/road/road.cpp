#include <iostream>
#include <cstdio>
using namespace std;
int n,m,k,ans,x[200005],y[200005],z[200005];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>x[i]>>y[i]>>z[i];
        if(x[i-1]!=0 && x[i-1]==x[i] || y[i-1]!=0 && y[i-1]==y[i])
        {
            ans+=min(z[i],z[i-1]);

        }

    }
    cout<<ans<<endl;
    return 0;

}
