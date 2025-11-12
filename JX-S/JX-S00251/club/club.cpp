#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e5+10;
int a[N],b[N],c[N];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    sort(c+1,c+n+1);
    if(b[n]==0&&c[n]==0)
    {
        int ans=0;
        for(int i=n;i>=n/2;i--)
        {
            ans+=a[i];
        }
        cout<<ans<<endl;
        return ;
    }
    else if(c[n]==0)
    {
        int ans=0;
        for(int i=n;i>=n/2;i--)
        {
            ans+=a[i];
       }
       for(int i=n;i>=n/2;i--)
       {
            ans+=b[i];
       }
       cout<<ans<<endl;
        return ;
    }
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=1;
    cin>>T;
    while(T--)
    {
        solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
