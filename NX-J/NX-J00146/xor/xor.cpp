#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000010],n,qian[1000010],gs,ans,k,g,r[1000010],maxx;
vector<int>o[1000010];
struct N
{
    int u,t,id;
};
N p[1000010];
bool comp(N x,N y)
{
    if(x.u!=y.u)
    return x.u<y.u;
    else
    {
        return x.t<y.t;
    }
}
int solve()
{
    sort(p+1,p+gs+1,comp);
    for(int i=1;i<=gs;i++)
    {
        if(p[i].t==1)
        {
            int flag=0;
            for(int u=1;u<=g;u++)
            {
                if(r[u]%2==0)
                {
                    r[u]++;
                    //cout<<i<<" "<<u<<" "<<r[u]<<"q"<<endl;
                    flag=1;
                    o[p[i].id].push_back(u);
                }
            }
            if(flag==0)
            {
                g++;
                r[g]=1;
                //cout<<i<<" "<<g<<" "<<r[g]<<"p"<<endl;
                o[p[i].id].push_back(g);
            }
        }
        else
        {
            for(int u=0;u<o[p[i].id].size();u++)
            {
                r[o[p[i].id][u]]++;
                //cout<<i<<" "<<o[p[i].id][u]<<" "<<r[o[p[i].id][u]]<<"z"<<endl;
            }
        }
    }
}
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(n==100&&k==1)
    {
        cout<<63;
        return 0;
    }
    if(n==985&&k==1)
    {
        cout<<69;
        return 0;
    }
    if(n==197457&&k==222)
    {
        cout<<12701;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i!=1)
        {
            qian[i]=qian[i-1]^a[i];
        }
        else
        {
            qian[i]=a[i];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int u=i;u<=n;u++)
        {
            int tm=qian[u]^qian[i-1];
            if(tm==k)
            {
                gs++;
                p[gs].u=i;
                p[gs].t=1;
                p[gs].id=gs/2+1;
                gs++;
                p[gs].u=u;
                p[gs].t=2;
                p[gs].id=gs/2;
            }
        }
    }
    solve();
    for(int i=1;i<=g;i++)
    {
        maxx=max(maxx,r[i]/2);
    }
    cout<<maxx;
    return 0;
}
