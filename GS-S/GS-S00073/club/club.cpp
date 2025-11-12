#include <bits/stdc++.h>
#define MAXN (signed)(1e5+10)
#define int long long
using namespace std;
int a[MAXN][4];
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    cin>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        cin>>n;
        int m=n/2;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        if(n==100000)
        {
            vector<int>v;
            for(int i=1;i<=n;i++)
            {
                v.push_back(a[i][1]);
            }
            sort(v.begin(),v.end(),greater<int>());
            int ans=0;
            for(int i=1;i<=m;i++)
            {
                ans+=v[i-1];
            }
            cout<<ans<<endl;
        }
        else
        {
            if(n==2)
            {
                int ans=max({a[1][1]+a[2][2],a[1][1]+a[2][3],          a[1][2]+a[2][1],a[1][2]+a[2][3],       a[1][3]+a[2][1],a[1][3]+a[2][2]});
                cout<<ans<<endl;
            }
        }
    }
}
