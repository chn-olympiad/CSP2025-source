#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int a[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int now=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        int nw=now^a[i];
        if(((nw^k)==0)||mp.count(nw^k))
        {
            ans++;
            mp.clear();
            now=0;
        }
        else
        {
            now=nw;
            mp[now]=1;
        }
    }
    cout<<ans<<'\n';
    return 0;
}