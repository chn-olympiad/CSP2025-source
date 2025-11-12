#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+7;
int n,q;
map<string,string>mp;

bool cmp(int l,int r,string s,string t,string ti)
{
    int j=0;
    for(int i=l;i<=r;i++,j++)
        s[i]=ti[j];
    return s==t;
}

int count(string s,string t)
{
    long long ans=0;
    for(int i=0;i<s.size();i++)
    {
        string y="";
        for(int j=i;j<s.size();j++)
        {
            y+=s[j];
            if(mp[y]!=""&&cmp(i,j,s,t,mp[y]))
                ans++;
        }
    }
    return ans;
}

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        string str,strr;
        cin>>str>>strr;
        mp[str]=strr;
    }
    for(int i=0;i<q;i++)
    {
        string s,t;
        cin>>s>>t;
        if(s.size()!=t.size()) cout<<0<<'\n';
        else cout<<count(s,t)<<'\n';
    }
    return 0;
}