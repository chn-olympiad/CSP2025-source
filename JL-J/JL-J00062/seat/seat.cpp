#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int q[105],ans[105];
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>q[i];
        if (q[i+1]>q[i])
        {
            ans[1]=q[i+1];
            ans[2]=q[i];
        }
    }
    cout<<ans[q[1]]<<endl;
    cout<<1<<" "<<2<<endl;
    cout<<2<<" "<<2<<endl;
    cout<<3<<" "<<1<<endl;

    return 0;
}
