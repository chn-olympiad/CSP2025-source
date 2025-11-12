#include<bits/stdc++.h>
using namespace std;

struct node
{
    string s1,s2;
};

int n,q;
node a[200005];

bool chk(string str1,string str2,node x)
{
    if (str1.size()!=str2.size()) return 0;
    for (int i=0; i<str1.size()-x.s1.size()+1; i++)
    {
        int flag=0;
        for (int j=i; j<i+x.s1.size(); j++)
        {
            if (!(str1[j]==x.s1[j-i]&&str2[j]==x.s2[j-i]))
            {
                flag=1;
                break;
            }
        }
        if (flag==1) continue;
        for (int j=0; j<i; j++)
        {
            if (str1[j]!=str2[j])
            {
                flag=1;
                break;
            }
        }
        if (flag==1) continue;
        for (int j=i+x.s1.size(); j<str1.size(); j++)
        {
            if (str1[j]!=str2[j])
            {
                flag=1;
                break;
            }
        }
        if (flag==1) continue;
        return 1;
    }
    return 0;
}

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i].s1>>a[i].s2;
    }
    while (q--)
    {
        string str1,str2;
        cin>>str1>>str2;
        int ans=0;
        for (int i=1; i<=n; i++)
        {
            ans+=chk(str1,str2,a[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}