#include<bits/stdc++.h>
using namespace std;
int find(string s1,string s2,int l)
{
    for(int i=l;i<s2.size()-s1.size();i++)
    {
        int x=i;
        for(int j=0;j<s1.size;j++)
        {
            if(s1[i]!=s2[i+j]) x=-1;
        }
        if(x!=-1) return x;
    }
    return -1;
}
string th(string s1,string s2,int l)
{
    for(int i=l;i<=l+s2.size(),i++)
    {
        s1[i]=s2[i-l];
    }
    return s1;
}
struct string2
{
    string s1,s2;
}s[2e5+5],t[2e5+5];
int main()
{
    int n,q,sum=0;
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i].s1>>s[i].s2;
    }
    for(int i=1;i<=q;i++)
    {
        cin>>t[i].s1>>t[i].s2;
    }
    for(int i=1;i<=q;i++)
    {
        int l[2e5+5][2e5+5]={0};
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                string s_x=t[j].s1;
                if(find(t[j].s1,s[k].s1,l[j][k])!=-1)
                {
                    while(find(t[j].s1,s[i].s1,l[j][k])!=-1)
                    {
                        l[j][k]=find(t[j].s1,s[i].s1,l[j][k]+1)
                        s_x=th(s_x,s[k].s1,l[j][k]);
                        if(s_x==t[j].s2) sum++;
                    }
                }
            }
        }
        cout<<sum<<endl;
        sum=0;
    }
    return 0;
}