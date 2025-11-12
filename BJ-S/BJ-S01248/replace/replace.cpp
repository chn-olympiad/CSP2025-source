#include <bits/stdc++.h>
#define int long long
using namespace std;
string s[200005][3];
int n,q;
void solve()
{
    string x,y;cin>>x>>y;
    if(x.size()!=y.size()) {cout<<0<<endl;return;}
    int l=-1,r=0;
    for(int i=0;i<x.size();i++)
    {
        if(x[i]!=y[i])
        {
            r=i;
            if(l==-1) l=i;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i][1].size()<r-l+1)
        {
            continue;
        }
        int left=0,right=0,flag=0;
        for(int j=0;j<x.size();j++)
        {
            if(x[j]==s[i][1][flag]&&flag<=s[i][1].size())
            {
                left=j;
                while(x[j]==s[i][1][flag])
                {
                    flag++,j++;
                }
                right=left+flag;
                if(flag==s[i][1].size()&&left<=l&&right>=r){ans++;break;}
                flag=0;
            }
        }
    }
    cout<<ans<<endl;
    return;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
    while(q--) solve();
    return 0;
}
