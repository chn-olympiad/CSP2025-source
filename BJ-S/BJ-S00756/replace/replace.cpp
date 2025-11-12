#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;

const int mod1=998244353;
const int mod2=1e9+9;
const int base1=131;
const int base2=13331;

int n,q;
pii ans[5000005];
map<pair<pii,pii>,vector<pair<pair<pii,int>,pair<pii,int>>>> mp;

int fpow(int a,int b,int p)
{
    int ans=1;
    while(b)
    {
        if(b&1)(ans*=a)%=p;
        (a*=a)%=p;
        b>>=1;
    }
    return ans;
}

pii gth(string s)
{
    pii ans={0,0};
    for(char i:s)
    {
        ans.fi=(ans.fi*base1%mod1+i)%mod1;
        ans.se=(ans.se*base2%mod2+i)%mod2;
    }
    return ans;
}

void gth2(string s)
{
    ans[s.size()+1]={-1,-1};
    int x=s.size();
    for(int i=0;i<x;i++)
    {
        ans[i+1].fi=(ans[i].fi*base1%mod1+s[i])%mod1;
        ans[i+1].se=(ans[i].se*base2%mod2+s[i])%mod2;
    }
}

pii gth3(int l,int r)
{
    return {(ans[r].fi+mod1-(ans[l-1].fi*fpow(base1,r-l+1,mod1)%mod1))%mod1,(ans[r].se+mod2-(ans[l-1].se*fpow(base2,r-l+1,mod2)%mod2))%mod2};
}

signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        string s,t;
        cin>>s>>t;
        if(s==t)
        {
            mp[{gth(s),gth(t)}].push_back({{gth(""),0},{gth(""),0}});
            continue;
        }
        int p1,p2;
        int x=s.size();
        for(int i=0;i<x;i++)
        {
            if(s[i]!=t[i])
            {
                p1=i;
                break;
            }
        }
        for(int i=x-1;i>=0;i--)
        {
            if(s[i]!=t[i])
            {
                p2=i;
                break;
            }
        }
        mp[{gth(s.substr(p1,p2-p1+1)),gth(t.substr(p1,p2-p1+1))}].push_back({{gth(s.substr(0,p1)),p1},{gth(s.substr(p2+1)),x-1-p2}});
    }
    while(q--)
    {
        string s,t;
        cin>>s>>t;
        if(s.size()!=t.size())
        {
            cout<<0<<'\n';
            continue;
        }
        if(s==t)
        {
            cout<<mp[{gth(s),gth(t)}].size()<<'\n';
            continue;
        }
        gth2(s);
        int p1,p2,ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=t[i])
            {
                p1=i;
                break;
            }
        }
        int x=s.size();
        for(int i=x-1;i>=0;i--)
        {
            if(s[i]!=t[i])
            {
                p2=i;
                break;
            }
        }
        for(const auto& i:mp[{gth(s.substr(p1,p2-p1+1)),gth(t.substr(p1,p2-p1+1))}])
        {
            if(i.fi.se==0&&i.se.se==0)
            {
                ans++;
                continue;
            }
            else if(i.fi.se==0)
            {
                if(gth3(p2+2,p2+i.se.se+1)==i.se.fi)
                {
                    ans++;
                }
            }
            else if(i.se.se==0)
            {
                if(gth3(p1-i.fi.se+1,p1)==i.fi.fi)
                {
                    ans++;
                }
            }
            else
            {
                if(gth3(p1-i.fi.se+1,p1)==i.fi.fi&&gth3(p2+2,p2+i.se.se+1)==i.se.fi)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
}
