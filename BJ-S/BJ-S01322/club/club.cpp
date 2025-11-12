#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
ll n;
array<ll,3>a[N];
array<ll,3>p;
multiset<pair<ll,ll> >ms[3];
void add(int o0,int o1,int o2)
{
    if(ms[o0].size()==n/2)
    {
        ms[ms[o0].begin()->second].insert({1e9,0});
        ms[o0].erase(ms[o0].begin());
    }
    if(p[o0]-p[o1]<p[o0]-p[o2])
    {
        ms[o0].insert({p[o0]-p[o1],o1});
    }
    else
    {
        ms[o0].insert({p[o0]-p[o2],o2});
    }
}
ll work()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }
    ms[0].clear();
    ms[1].clear();
    ms[2].clear();
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        p=a[i];
        if(ms[0].size()==n/2)p[0]-=ms[0].begin()->first;
        if(ms[1].size()==n/2)p[1]-=ms[1].begin()->first;
        if(ms[2].size()==n/2)p[2]-=ms[2].begin()->first;
        if(p[0]==max({p[0],p[1],p[2]}))
        {
            ans+=p[0];
            p=a[i];
            add(0,1,2);
        }
        else if(p[1]==max({p[0],p[1],p[2]}))
        {
            ans+=p[1];
            p=a[i];
            add(1,0,2);
        }
        else if(p[2]==max({p[0],p[1],p[2]}))
        {
            ans+=p[2];
            p=a[i];
            add(2,0,1);
        }
    }
    return ans;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)cout<<work()<<'\n';
    return 0;
}
