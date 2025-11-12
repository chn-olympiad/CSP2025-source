#include<bits/stdc++.h>
using namespace std;
unordered_map<long long,int>mp;
string s,t;
int n,q;
const int p=998244353,mod1=1000000007,mod2=1000000009;
long long merge(int x,int y){return ((long long)x<<32|y);}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    if(n>=10000)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>s>>t;
            int h1=0,h2=0,f=0;
            for(int i=0;i<s.size();i++)
            {
                if(s[i]!=t[i])f=!f;
                if(!f)continue;
                h1=(1LL*h1*p%mod1+(s[i]-'0'+26)*(t[i]-'0'))%mod1;
                h2=(1LL*h2*p%mod2+(s[i]-'0'+26)*(t[i]-'0'))%mod2;
            }
            mp[merge(h1,h2)]++;
        }
        while(q--&&cin>>s>>t)
        {
            int h1=0,h2=0,f=0;
            for(int i=0;i<s.size();i++)
            {
                if(s[i]!=t[i])f=!f;
                if(!f)continue;
                h1=(1LL*h1*p%mod1+(s[i]-'0'+26)*(t[i]-'0'))%mod1;
                h2=(1LL*h2*p%mod2+(s[i]-'0'+26)*(t[i]-'0'))%mod2;
            }
            cout<<mp[merge(h1,h2)]<<"\n";
        }
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>s>>t;
        int h1=0,h2=0;
        for(int i=0;i<s.size();i++)
        {
            h1=(1LL*h1*p%mod1+(s[i]-'0'+26)*(t[i]-'0'))%mod1;
            h2=(1LL*h2*p%mod2+(s[i]-'0'+26)*(t[i]-'0'))%mod2;
        }
        mp[merge(h1,h2)]++;
    }
    while(q--&&cin>>s>>t)
    {
        int a=s.size(),b=-1;
        int ans=0;
        for(int i=0;i<s.size();i++)
            if(s[i]!=t[i])
                a=min(a,i),b=max(b,i);
        // cout<<a<<" "<<b<<endl;
        for(int i=0;i<s.size();i++)
            {
                int h1=0,h2=0;
                for(int j=i;j<s.size();j++)
                {
                    h1=(1LL*h1*p%mod1+(s[j]-'0'+26)*(t[j]-'0'))%mod1;
                    h2=(1LL*h2*p%mod2+(s[j]-'0'+26)*(t[j]-'0'))%mod2;
                    if(i<=a&&b<=j)ans+=mp[merge(h1,h2)];//,cout<<s.substr(i,j-i+1)<<endl;
                }
            }
        cout<<ans<<"\n";
    }
    return 0;
}
/*
g++ replace.cpp -o replace
replace.exe

// freopen("replace.in","r",stdin);
// freopen("replace.out","w",stdout);
// freopen("replace.in","r",stdin);
// freopen("replace.out","w",stdout);
// freopen("replace.in","r",stdin);
// freopen("replace.out","w",stdout);
// freopen("replace.in","r",stdin);
// freopen("replace.out","w",stdout);
// freopen("replace.in","r",stdin);
// freopen("replace.out","w",stdout);
*/