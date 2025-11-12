#include<bits/stdc++.h>
using namespace std;
int n,q;
struct ed
{
    string s1,s2;
}e[200010];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)   cin>>e[i].s1>>e[i].s2;
    for(int i=1;i<=q;i++)
    {
        string t1,t2;
        cin>>t1>>t2;
        int ans=0;
        int l=t1.size();
        for(int j=1;j<=n;j++)
        {
            int len=e[j].s1.size();
            if(len<=l)
            {
                for(int u=0;u<=l-len;u++)
                {
                    if(u+len>l)    break;
                    string ls=t1;
                    int flag=0;
                    for(int v=0;v<len;v++)
                    {
                        if(ls[u+v]!=e[j].s1[v]) {flag=1;break;}
                        else    ls[u+v]=e[j].s2[v];
                    }
                    //cout<<ls<<" "<<e[j].s1<<endl;
                    if(flag==0)
                    {
                        for(int v=0;v<l;v++)
                            if(ls[v]!=t2[v])    {flag=1;break;}
                    }
                    if(flag==0) ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
