#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],num[500005];
map <int,int> mp;
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,k,ans=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        num[i]=num[i-1]^a[i];
    }
    int last=0;
    mp[0]++;
    for(int i=1;i<=n;i++)
    {

        if(a[i]==k)
        {
            ans++;
            //cout<<i<<endl;
            last=i;
            mp.clear();
            mp[num[i]^num[last]]++;
            continue;
        }
        int x=num[i]^k^num[last];
        if(mp[x]>0)
        {
            ans++;
            //cout<<i<<endl;
            mp.clear();
            last=i;
        }
        mp[num[i]^num[last]]++;
    }
    cout<<ans;
}
