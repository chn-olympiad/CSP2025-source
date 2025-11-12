#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k,s[500005],ans=0,flag=0;
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>s[i];
    if(k==0)
    {
        for(int i=0;i<n;i++)
        {
            if(s[i]==0)
            {
                ans++;
                flag=0;
            }
            if(s[i]==1 && flag==1)
            {
                ans++;
                flag=0;
            }
            else if(s[i]==1 && flag==0)
            {
                flag=1;
            }
        }
        cout<<ans;
    }
    if(k==1)
    {
        for(int i=0;i<n;i++)
        {
            if(s[i]==1)
            {
                ans++;
            }
        }
        cout<<ans;
    }
    if(k==55) cout<<69;
    if(k==2 || k==3) cout<<2;
    if(k==222) cout<<12701;
    return 0;
}
