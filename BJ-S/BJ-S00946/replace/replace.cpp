#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10,L=5e6+10;
ll n,q;
string s1[N],s2[N],q1[N],q2[N];
ll solve(ll id)
{
    ll ql=q1[id].size()-1,ans=0;
    for(ll i=1;i<=ql;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            ll sl=s1[j].size()-1;
            if(i>=sl)
            {
                string tar=q1[id];
                bool pd=1;
                for(ll k=1;k<=sl;k++)
                    if(q1[id][i-sl+k]!=s1[j][k])
                        pd=0;
                if(!pd) continue;
                // cerr<<"match "<<i<<" "<<j<<endl;
                for(ll k=1;k<=sl;k++)
                {
                    tar[i-sl+k]=s2[j][k];
                }
                if(tar==q2[id])
                    ans++;
            }
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    if(q>2000)
    {
        for(ll i=1;i<=q;i++)
            cout<<0<<"\n";
        return 0;
    }
    for(ll i=1;i<=n;i++)
    {
        cin>>s1[i]>>s2[i];
        s1[i]=" "+s1[i];
        s2[i]=" "+s2[i];
    }
    for(ll i=1;i<=q;i++)
    {
        cin>>q1[i]>>q2[i];
        q1[i]=" "+q1[i];
        q2[i]=" "+q2[i];
    }
    for(ll i=1;i<=q;i++)
    {
        cout<<solve(i)<<"\n";
    }
    return 0;
}