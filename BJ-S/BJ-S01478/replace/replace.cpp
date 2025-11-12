//AFOing.
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=200050;
string s[N][3],t[3];
ll ans;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i][1]>>s[i][2];
    }
    while(q--)
    {
        ans=0;
        cin>>t[1]>>t[2];
        if(t[1].size()!=t[2].size())
        {
            cout<<0<<'\n';
            continue;
        }
        int lt=t[1].size(),qb1,qb2;
        for(int j=0;j<lt;j++)
        {
            if(t[1][j]=='b')
            {
                qb1=j;
            }
            if(t[2][j]=='b')
            {
                qb2=j;
            }
            if(qb1&&qb2)
            {
                break;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(s[i][1].size()>t[1].size())
            {
                continue;
            }
            int b1=0,b2=0,ls=s[i][1].size();
            for(int j=0;j<ls;j++)
            {
                if(s[i][1][j]=='b')
                {
                    b1=j;
                }
                if(s[i][2][j]=='b')
                {
                    b2=j;
                }
                if(b1&&b2)
                {
                    break;
                }
            }
            if(qb1<qb2&&b1<b2&&qb1>=b1&&ls-b2<=lt-qb2)
            {
                if(qb2-qb1==b2-b1)
                {
                    ans++;
                }
            }
            else if(qb1>qb2&&b1>b2&&lt-qb1>=ls-b1&&b2<=qb2)
            {
                if(qb1-qb2==b1-b2)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
