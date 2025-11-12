#include<bits/stdc++.h>
using namespace std;
#define int long long
map<pair<string,string>,vector<pair<string,int>>> mp;
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string s1,s2;
        cin>>s1>>s2;
        assert(s1.size()==s2.size());
        int l=0;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]==s2[i]) l++;
            else break;
        }
        int r=s1.size()-1;
        for(int i=s1.size()-1;i>=0;i--)
        {
            if(s1[i]==s2[i]) r--;
            else break;
        }
        string a="",b="";
        for(int i=l;i<=r;i++)
        {
            a+=s1[i];
            b+=s2[i];
        }
        //cout<<a<<" "<<b<<endl;
        mp[make_pair(a,b)].push_back(make_pair(s1,l));
    }
    while(m--)
    {
        string s1,s2;
        cin>>s1>>s2;
        if(s1.size()!=s2.size())
        {
            cout<<0<<endl;
            continue;
        }
        int l=0;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]==s2[i]) l++;
            else break;
        }
        int r=s1.size()-1;
        for(int i=s1.size()-1;i>=0;i--)
        {
            if(s1[i]==s2[i]) r--;
            else break;
        }
        string a="",b="";
        for(int i=l;i<=r;i++)
        {
            a+=s1[i];
            b+=s2[i];
        }
        int ans=0;
        for(auto x:mp[make_pair(a,b)])
        {
            string s=x.first;
            int id=x.second;
            int L=l-id;
            if(L<0||L+s.size()-1>=s1.size()) continue;
            bool flag=true;
            for(int i=L,j=0;i<=L+s.size()-1;i++,j++)
            {
                if(l<=i&&i<=r) continue;
                //cout<<s1[i]<<" "<<s[j]<<" "<<" "<<l<<" "<<r<<endl;
                if(s1[i]!=s[j])
                {
                    flag=false;
                    break;
                }
            }
            ans+=flag;
        }
        cout<<ans<<endl;
    }
    return 0;
}
