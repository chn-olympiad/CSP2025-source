#include<bits/stdc++.h>
const int N=1e5+5;
#define int long long
using namespace std;
int n,T;
struct node
{
    int a1,a2,a3;
    int val;
}p[N],p1[N],p2[N],p3[N];
void solve()
{
    int ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>p[i].a1>>p[i].a2>>p[i].a3;
    int t1=0,t2=0,t3=0;
    for(int i=1;i<=n;i++)
    {
        int maxn=max({p[i].a1,p[i].a2,p[i].a3});
        if(maxn==p[i].a1)
        {
            p[i].val=min(p[i].a1-p[i].a2,p[i].a1-p[i].a3);
            p1[++t1]=p[i];
        }
        else if(maxn==p[i].a2)
        {
            p[i].val=min(p[i].a2-p[i].a1,p[i].a2-p[i].a3);
            p2[++t2]=p[i];
        }
        else if(maxn==p[i].a3)
        {
            p[i].val=min(p[i].a3-p[i].a1,p[i].a3-p[i].a2);
           // cerr<<i<<' '<<p[i].val<<'\n';
            p3[++t3]=p[i];
        }
        ans+=maxn;
    }
    if(t1>n/2)
    {
        sort(p1+1,p1+t1+1,[](node x,node y){return x.val>y.val;});
        while(t1>n/2)
        {
            ans-=p1[t1].val;
            t1--;
        }
    }
    else if(t2>n/2)
    {
        
        sort(p2+1,p2+t2+1,[](node x,node y){return x.val>y.val;});
        while(t2>n/2)
        {
            ans-=p2[t2].val;
            t2--;
        }
    }
    else if(t3>n/2)
    {
        sort(p3+1,p3+t3+1,[](node x,node y){return x.val>y.val;});
        while(t3>n/2)
        {
            ans-=p3[t3].val;
            t3--;
        }
    }
    cout<<ans<<'\n';
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--)
    {
        solve();
    }
}