#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[500005],ans,sum[500005],last;
struct Node
{
    ll l,r;
};
bool cmp(Node a,Node b)
{
    if(a.r==b.r)
        return a.l<b.l;
    return a.r<b.r;
}
vector<Node> g;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
    }
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            if((sum[j]^sum[i-1])==k)
                g.push_back({i,j});
    sort(g.begin(),g.end(),cmp);
    for(auto w:g)
    {
        if(last<w.l)
            last=w.r,ans++;
    }
    cout<<ans;
    return 0;
}
