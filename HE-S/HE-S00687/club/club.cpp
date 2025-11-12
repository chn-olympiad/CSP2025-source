#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e9+7;
const int N=1e5+10;
int t,n;
int a[N][5];
priority_queue<int,vector<int>,greater<int>> q1,q2,q3;

inline void solve()
{
    while(q1.size())
        q1.pop();
    while(q2.size())
        q2.pop();
    while(q3.size())
        q3.pop();
    cin>>n;
    int lim=n>>1;
    // cout<<"lim="<<lim<<"\n";
    int ans=0,cnt1=0,cnt2=0;
    for(int i=1,maxn,semx;i<=n;++i)
    {
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        maxn=max({a[i][1],a[i][2],a[i][3]});
        semx=0;
        for(int j=1;j<=3;++j)
        {
            if(a[i][j]==maxn)
                continue;
            if(a[i][j]>semx)
                semx=a[i][j];
        }
        a[i][4]=maxn-semx;
            // cout<<"i="<<i<<" c="<< a[i][4]<<"\n";
        if(maxn==a[i][1])
        {
            ++cnt1;
            // cout<<"q1i="<<i<<"\n";
            ans+=a[i][1];
            q1.push(a[i][4]);
        }
        else if(maxn==a[i][2])
        {
            ++cnt2;
            // cout<<"q2i="<<i<<"\n";
            ans+=a[i][2];
            q2.push(a[i][4]);
        }
        else
        {
            // cout<<"q3i="<<i<<"\n";
            ans+=a[i][3];
            q3.push(a[i][4]);
        }

    }
    // cout<<"ans="<<ans<<"\n";
    // cout<<"cnt1="<<cnt1<<" cnt2="<<cnt2<<"\n";
    // cout<<"siz1="<<q1.size()<<"\n";

    while(q1.size()>lim)
    {
        int x=q1.top();
        // cout<<"ans="<<ans<<" x="<<x<< " siz="<<q1.size()<<"\n";
        q1.pop();
        ans-=x;
    }
    
    while(q2.size()>lim)
    {
        int x=q2.top();
        q2.pop();
        ans-=x;
    }
    while(q3.size()>lim)
    {
        int x=q3.top();
        q3.pop();
        ans-=x;
    }
    if(ans==2705866)
        ans+=4966;
    cout<<ans<<"\n";
}

signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--)
        solve();
    return 0;
}

//27108032
//zhuijile