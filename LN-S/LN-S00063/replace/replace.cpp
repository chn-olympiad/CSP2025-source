#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,q;
long long ans;
string s[maxn][3],t[maxn][3];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i][1]>>s[i][2];
    }
    for(int i=1;i<=q;i++)
    {
        ans=0;
        cin>>t[i][1]>>t[i][2];
        for(int j=1;j<=n;j++)
        {
            int mrka=t[i][1].find(s[j][1]);
            int mrkb=t[i][2].find(s[j][2]);
            if(mrka>=0&&mrkb>=0)
            {
                string stra=t[i][1],strb=t[i][2];
                stra.erase(mrka,s[j][1].size());
                strb.erase(mrkb,s[j][2].size());
                //cout<<stra<<strb;
                if(stra==strb)ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
