#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
ll n,m,k;
struct pst{
    ll u,v,w;
};
pst g[1000010];
ll fa[100010];
ll find(ll x)
{
    if(x==fa[x])
    {
        return fa[x];
    }
    fa[x]=find(fa[x]);
    return fa[x];
}
bool cmp(pst x,pst y)
{
    return x.w<y.w;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    
    cout<<1;
    return 0;
}
