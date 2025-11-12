#include<bits/stdc++.h>
using namespace std;
string s1,s2;
unordered_map<string,vector<pair<string,string>>> mp;
bool check(string str,string s)
{
    if(str.size()<s.size())
    {
        return 0;
    }
    for(int i=str.size()-1,j=s.size()-1;j>=0;i--,j--)
    {
        if(str[i]!=s[j])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s1>>s2;
        int idx1,idx2;
        for(int j=0;j<s1.size();j++)
        {
            if(s1[j]!=s2[j])
            {
                idx1=j;
                break;
            }
        }
        for(int j=s1.size()-1;j>=0;j--)
        {
            if(s1[j]!=s2[j])
            {
                idx2=j;
                break;
            }
        }
        string tmp;
        for(int i=idx1;i<=idx2;i++)
        {
            tmp+=s1[i];
            tmp+=s2[i];
        }
        string st,ed;
        for(int i=0;i<idx1;i++)
        {
            st+=s1[i];
        }
        for(int i=s1.size()-1;i>idx2;i--)
        {
            ed+=s1[i];
        }
        mp[tmp].push_back({st,ed});
    }
    while(q--)
    {
        cin>>s1>>s2;
        int idx1,idx2;
        for(int j=0;j<s1.size();j++)
        {
            if(s1[j]!=s2[j])
            {
                idx1=j;
                break;
            }
        }
        for(int j=s1.size()-1;j>=0;j--)
        {
            if(s1[j]!=s2[j])
            {
                idx2=j;
                break;
            }
        }
        string tmp;
        for(int i=idx1;i<=idx2;i++)
        {
            tmp+=s1[i];
            tmp+=s2[i];
        }
        string st,ed;
        for(int i=0;i<idx1;i++)
        {
            st+=s1[i];
        }
        for(int i=s1.size()-1;i>idx2;i--)
        {
            ed+=s1[i];
        }
        int cnt=0;
        for(auto [sti,edi]:mp[tmp])
        {
            if(check(st,sti)&&check(ed,edi))
            {
                cnt++;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}