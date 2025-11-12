#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define int long long
#define endl '\n'
int n,ans;
pair<int,int> a[5];
vector<int> v[5];
priority_queue<pair<int,int> > q;
void solve()
{
    //v[1].clear(),v[2].clear(),v[3].clear();
    //while(!q.empty())q.pop();
    //ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[1].fi>>a[2].fi>>a[3].fi;
        a[1].se=1,a[2].se=2,a[3].se=3;
        sort(a+1,a+1+3);
        v[a[3].se].push_back(a[3].fi);
        ans+=a[3].fi;
        q.push({a[2].fi-a[3].fi,a[3].se});
    }
    if(v[1].size()<=n/2&&v[2].size()<=n/2&&v[3].size()<=n/2)
    {
        cout<<ans<<endl;
    }
    else
    {
        int flog;
        if(v[1].size()>n/2)flog=1;
        else if(v[2].size()>n/2)flog=2;
        else if(v[3].size()>n/2)flog=3;
        //cout<<flog<<endl;//
        int cnt=0;
        while(v[flog].size()-cnt>n/2&&!q.empty())
        {
            pair<int,int> x=q.top();
            q.pop();
            //cout<<x.fi<<" "<<x.se<<endl;
            if(x.se!=flog) ;
            else
            {
                ans+=x.fi;
                cnt++;
            }
        }
        cout<<ans<<endl;
    }
    v[1].clear(),v[2].clear(),v[3].clear();
    while(!q.empty())q.pop();
    ans=0;
    return;
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}
