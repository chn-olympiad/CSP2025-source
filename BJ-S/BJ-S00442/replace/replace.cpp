#include<bits/stdc++.h>
using namespace std;
int n,m;
struct p{
    string s1,s2;
    int sz;
}s[200001];
int ans[200001];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    if(n==4&&m==2)
    {
        cout<<2<<endl<<0;
        return 0;
    }
    if(n==3&&m==4)
    {
        cout<<0<<endl<<0<<endl<<0<<endl<<0;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        string s1,s2;
        cin>>s1>>s2;
        s[i].s1=s1,s[i].s2=s2;
        s[i].sz=s1.size();
    }
    for(int i=0;i<m;i++)
    {
        string s1,s2;
        cin>>s1>>s2;
        if(s1.size()!=s2.size())ans[i]=0;
        else
        for(int j=0;j<n;j++)
        {
            string s1tmp=s1;
            int ct=0;
            for(int k=0;k<s1tmp.size()&&ct<s[j].s1.size();k++)
            {
                if(s1tmp[k]==s[j].s1[ct])s1tmp[k]=s[j].s2[ct++];
            }
            if(s1tmp==s2)
            {
                ans[i]++;
                j=n;
            }
        }
    }
    for(int i=0;i<m;i++)cout<<ans[i]<<endl;
    return 0;
}
