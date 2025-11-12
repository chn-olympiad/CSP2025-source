#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
pair<string,string> s[N],t[N];
int n,q,ans;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        cin>>s[i].first>>s[i].second;
    }
    for(int i=1;i<=q;i++)
    {
        cin>>t[i].first>>t[i].second;
    }
    for(int j=1;j<=q;j++)
    {
        ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int k=0;k<s[i].first.length();k++)
            {
                int p1=k,p2=0;
                if(s[i].first[p1]==t[j].first[p2] && s[i].second[p1]==t[j].second[p2])
                {
                    string ss=s[i].first;
                    for(int g=p1;g<=t[j].first.length();g++)
                    {
                        if(ss[g]==t[j].first[g-p1])
                        {
                            ss[g]=t[i].first[g-p1];
                        }
                        else break;
                    }
                    if(ss.length()==s[i].second.length())
                    {
                        bool flag=1;
                        for(int g=0;g<ss.length();g++)
                        {
                            if(ss[g]!=s[i].second[g])
                            {
                                flag=0;
                                break;
                            }
                        }
                        if(flag==1) ans++;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

