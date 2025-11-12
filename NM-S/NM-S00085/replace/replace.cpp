#include<bits/stdc++.h>
using namespace std;
int n,q,cnt=1,ans;
string s1,s2,t1,t2;
struct tire{
    vector<string> s;
    int son[26];
}t[2000006];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        cin>>s1>>s2;
        for(int i=0,nw=1;i<s1.size();i++)
        {
            if(t[nw].son[s1[i]-'a']==0)
                t[nw].son[s1[i]-'a']=++cnt;
            nw=t[nw].son[s1[i]-'a'];
            if(i==s1.size()-1)
                t[nw].s.push_back(s2);
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>t1>>t2;
        ans=0;
        for(int i=0;i<t1.size();i++)
        {
            if(i>0&&t1[i-1]!=t2[i-1])
                break;
            for(int j=i,nw=1;j<t1.size();j++)
            {
                if(t[nw].son[t1[j]-'a']==0)
                    break;
                nw=t[nw].son[t1[j]-'a'];
                if(t[nw].s.size()!=0)
                {
                    bool f=0;
                    for(int k=j+1;k<t1.size();k++)
                        if(t1[k]!=t2[k])
                        {
                            f=1;
                            break;
                        }
                    if(f==1)
                        continue;
                    for(auto y:t[nw].s)
                    {
                        f=0;
                        for(int k=i;k<=j;k++)
                            if(y[k-i]!=t2[k])
                            {
                                f=1;
                                break;
                            }
                        if(f==0)
                            ans++;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
