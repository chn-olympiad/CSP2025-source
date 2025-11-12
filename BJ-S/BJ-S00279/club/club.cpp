#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
ll n;
ll a[100005][3];
ll as[100005],ca,bs[100005],cb,cs[100005],cc,ans;
ll mx(ll x)
{
    return max(max(a[x][0],a[x][1]),a[x][2]);
}
priority_queue<ll,vector<ll>,greater<ll> > q1;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ll T;
    cin>>T;
    while(T--)
    {
        while(q1.size())q1.pop();
        ans=ca=cb=cc=0;
        memset(a,0,sizeof(a));
        memset(as,0,sizeof(as));
        memset(bs,0,sizeof(bs));
        memset(cs,0,sizeof(cs));
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            if(mx(i)==a[i][0])
            {
                as[++ca]=i;
            }
            else if(mx(i)==a[i][1])
            {
                bs[++cb]=i;
            }
            else
            {
                cs[++cc]=i;
            }
            ans+=mx(i);
        }
        if(ca>n/2)
        {
            for(int i=1;i<=ca;i++)
            {
                ll ai=as[i];
                q1.push(min(a[ai][0]-a[ai][1],a[ai][0]-a[ai][2]));
            }
            for(int i=1;i<=ca-n/2;i++)
            {
                ans-=q1.top();
                q1.pop();
            }
        }
        else if(cb>n/2)
        {
            for(int i=1;i<=cb;i++)
            {
                ll ai=bs[i];
                q1.push(min(a[ai][1]-a[ai][0],a[ai][1]-a[ai][2]));
            }
            for(int i=1;i<=cb-n/2;i++)
            {
                ans-=q1.top();
                q1.pop();
            }
        }
        else if(cc>n/2)
        {
            for(int i=1;i<=cc;i++)
            {
                ll ai=cs[i];
                q1.push(min(a[ai][2]-a[ai][0],a[ai][2]-a[ai][1]));
            }
            for(int i=1;i<=cc-n/2;i++)
            {
                ans-=q1.top();
                q1.pop();
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
