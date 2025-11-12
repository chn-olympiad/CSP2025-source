#include<bits/stdc++.h>
using namespace std;
string a[2001],b[2001];
#define int long long
constexpr int mod1=998244353,mod2=1000000007;constexpr int base=127;
__inline int qpow(int base,int p,int mod)
{
    int ans=1;
    while(p)
    {
        if(p&1)ans=ans*base%mod;
        base=base*base%mod;
        p>>=1;
    }
    return ans;
}
struct hash1
{
    int v[2010];
    inline void get_hash(string s)
    {
        v[0]=s[0]-'a'+1;
        for(int i=1;i<s.size();i++)
        {
            v[i]=v[i-1]*base%mod1+(s[i]-'a'+1);
        }
    }
    inline long long query(int l,int r)
    {
        return (v[r]-v[l-1])*qpow(base,mod1-(r-l+1),mod1);
    }
};
#undef int
int main()
{
    freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
    ios::sync_with_stdio();cin.tie(0);
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    string s1,s2;
    for(int i=1;i<=q;i++)
    {
        cin>>s1>>s2;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0,x;j<s1.size()-a[i].size()+1;j++)
            {
                for(x=j;x<j+a[i].size();x++)
                    if(s1[x]!=a[i][x-j])break;
                if(x==j+a[i].size())
                {
                    // clog<<a[i]<<' '<<j<<' '<<s1<<' '<<s2<<'\n';
                    for(x=0;x<s1.size();x++)
                    {
                        if(j<=x&&x<j+a[i].size())
                        {
                            // clog<<" "<<x<<'\n';
                            if(b[i][x-j]!=s2[x])break;
                        }
                        else if(s1[x]!=s2[x])break;
                    }
                    if(x==s1.size())ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
/*
好家伙，刚想到三次方做法，没时间了
只能整活了
Man, what can I say?
MANBA out.

//100+100+10+20,Too candy. 
*/
