#include <bits/stdc++.h>

using namespace std;
int n,q;
string s[100010][2];
string t[100010][2];
void solve1()
{

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i][0]>>s[i][1];
    }
    for(int i=1;i<=q;i++)
    {
        cin>>t[i][0]>>t[i][1];
    }
    for(int z=1;z<=q;z++)
    {
        int l=-1,r=0;
        for(int i=0;i<=t[z][0].size()-1;i++)
        {
            if(t[z][0][i]!=t[z][1][i])
            {
                if(l==-1) l=i;
                r=i;
            }
        }
        int ans=0;
        for(int i=0;i<=l;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[j][0].size()+i<=r) continue;
                bool b=1;
                for(int k=0;k<=s[j][0].size()-1;k++)
                {
                    if(t[z][0][i+k]!=s[j][0][k]||t[z][1][i+k]!=s[j][1][k]) b=0;
                }
                ans+=b;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
