#include<bits/stdc++.h>
using namespace std;
int n,k,a[500009],_xor[500009];
vector<int>pos[(2<<20)-1];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        _xor[i]=_xor[i-1]^a[i];
        pos[_xor[i]].push_back(i);
    }
    int r=0,ans=0;
    for(int i=1;i<=n;++i)
    {
        if(a[i]==k||(_xor[i]^_xor[r])==k)
        {
            r=i;
            ++ans;
            continue;
        }
        int w=_xor[i]^k;
        auto p=upper_bound(pos[w].begin(),pos[w].end(),r);
        if(p!=pos[w].end()&&*p<i)
        {
            r=i;
            ++ans;
        }
    }
    cout<<ans;
    return 0;
}