#include<bits/stdc++.h>
using namespace std;
int a[101010][4];
int c[101010];
int d[4];
inline int solve()
{
    memset(d,0,sizeof(d));
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])c[i]=1;
        else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])c[i]=2;
        else c[i]=3;
        d[c[i]]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans+=a[i][c[i]];
    for(int x=1;x<=3;x++)
    {
        if(d[x]>n/2)
        {
            priority_queue<int> q;
            for(int i=1;i<=n;i++)
            {
                if(c[i]==x)
                {
                    if(x==1)q.push(max(a[i][2],a[i][3])-a[i][1]);
                    else if(x==2)q.push(max(a[i][1],a[i][3])-a[i][2]);
                    else q.push(max(a[i][1],a[i][2])-a[i][3]);
                }
            }
            while(q.size()>n/2)
            {
                ans+=q.top(),q.pop();
            }
            cout<<ans<<'\n';
            return 0;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
int main()
{
    freopen("club.in","r",stdin);freopen("club.out","w",stdout);
    int t;cin>>t;
    while(t--)
        solve();
    return 0;
}