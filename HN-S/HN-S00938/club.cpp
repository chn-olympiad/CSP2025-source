#include<bits/stdc++.h>
#define int long long 
using namespace std;
int t,n,tot,ans;
vector <int > q[5];
int a[100005][5];
void clear()
{
    tot=ans=0;
    for(int i=1;i<=3;i++) q[i].clear();
}
int cmp(int x,int y)
{
    return x>y;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int maxx=-1,now=-INT_MAX;
            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j];
                if(maxx==-1||a[i][j]>a[i][maxx]) maxx=j;
            }
            for(int j=1;j<=3;j++)
                if(j!=maxx)
                    now=max(now,a[i][j]-a[i][maxx]);
            q[maxx].push_back(now);ans+=a[i][maxx];
        }
        for(int i=1;i<=3;i++)
        {
            int cnt=q[i].size()-n/2;
            sort(q[i].begin(),q[i].end(),cmp);
            for(int j=0;j<cnt;j++)
                ans+=q[i][j];
        }
        cout<<ans<<"\n";
        clear();
    }
}