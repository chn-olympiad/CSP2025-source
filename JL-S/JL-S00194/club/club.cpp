#include <bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],f[100005],ans;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            f[i]=max(a[i][1],max(a[i][2],a[i][3]));
            ans+=f[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
