#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <bitset>
#include <array>

using namespace std;

#define fori(i,a,b)     for(int i=(a);i<=(b);i++)
#define fori0(i,a,b)    for(int i=(a);i<(b);i++)
#define ford(i,a,b)     for(int i=(a);i>=(b);i--)
#define rgall(a)        (a).begin(),(a).end()
#define rgany(a,l,r)    (a).begin()+(l),(a).begin()+(r)
#define rgn(a,n)        rgany(a,0,n)
#define rgo1(a,n)       rgany(a,1,n+1)

ifstream cin("road.in");
ofstream cout("road.out");

struct edge
{
    int u,v;
    long long w;
    int a;
    bool operator<(const edge& b)const
    {
        return w<b.w;
    }
};

array<long long,101> va;
array<int,10101> dsu;
vector<edge> ve,ve0;

int dsurt(int u)
{
    return u==dsu[u]?u:dsu[u]=dsurt(dsu[u]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,na;
    cin>>n>>m>>na;
    fori(i,1,m)
    {
        int u,v,w;
        cin>>u>>v>>w;
        ve0.push_back((edge){u,v,w});
    }
    fori(i,1,n)
        dsu[i]=i;
    sort(rgall(ve0));
    for(const edge& i:ve0)
    {
        int u=dsurt(i.u),v=dsurt(i.v);
        if(u!=v)
            ve.push_back(i),dsu[u]=v;
    }
    fori0(i,0,na)
    {
        cin>>va[i];
        fori(j,1,n)
        {
            int a;
            cin>>a;
            ve.push_back((edge){n+1+i,j,a,1<<i});
        }
    }
    sort(rgall(ve));
    long long ans=1e18;
    fori0(i,0,1<<na)
    {
        fori(j,0,n+na)
            dsu[j]=j;
        int a=n;
        long long ans0=0;
        fori0(j,0,na)
            if(i&1<<j)
                ++a,ans0+=va[j];
        for(const edge& j:ve)
        {
            if((j.a&i)!=j.a)
                continue;
            int u=dsurt(j.u),v=dsurt(j.v);
            if(u!=v)
            {
                dsu[u]=v,ans0+=j.w;
                if(!--a)
                    break;
            }
        }
        ans=min(ans,ans0);
        // cout<<i<<' '<<ans0<<endl;
    }
    cout<<ans<<'\n';
    return 0;
}
//0.5h+0.5h+0.5h+2.5h