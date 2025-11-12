#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[205],s2[205];
string t1,t2;
int ans=0;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
    while(q--)
    {
        cin>>t1>>t2;
        ans=0;
        for(int i=1;i<=n;i++)
        {
            if(s1[i].size()>t1.size())continue;
            for(int j=0;j+s1[i].size()<=t1.size();j++)
            {
                if(t1.substr(j,s1[i].size())!=s1[i])continue;
                string p="";
                if(j>0)p+=t1.substr(0,j);
                p+=s2[i];
                if(j+s1[i].size()<t1.size())p+=t1.substr(j+s1[i].size());
                if(p==t2)ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
