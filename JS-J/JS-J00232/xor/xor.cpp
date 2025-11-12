#include<bits/stdc++.h>
using namespace std;
int n,k,x[500010],ans=1,sum[500010];
struct node
{
    int l,r;
};
bool cmp(node a,node b){return a.r<b.r;}
vector<node>v;
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>x[i],sum[i]=sum[i-1]^x[i];
    for(int i=1;i<=n;++i)
        for(int j=i;j<=n;++j)
            if((sum[j]^sum[i-1])==k)
            {
                v.push_back({i,j});
                break;
            }
    if(!v.size())cout<<0,exit(0);
    //cerr<<v.size()<<endl;
    sort(v.begin(),v.end(),cmp);
    //for(auto&[l,r]:v)cerr<<l<<' '<<r<<endl;
    int ls=v[0].r;
    for(int i=1;i<v.size();++i)if(v[i].l>ls)ans++,ls=v[i].r;
    cout<<ans;
    return 0;
}
