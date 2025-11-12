#include<bits/stdc++.h>
using namespace std;
map<string,string> mp;
map<string,bool> vis;
int n,q,ans=0;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        string s,t;
        cin>>s>>t;
        mp[s]=t;
    }
    while(q--)
    {
        string s,t;
        cin>>s>>t;
        ans=0;
        for(auto i:mp)
        {
            string k=i.first,v=i.second;
            int spos=s.find(k),tpos=t.find(v);
            if(spos!=-1&&spos==tpos)
            {
                string sx=s.substr(0,spos),sy=k,sz=s.substr(spos+k.size());
                string tx=t.substr(0,tpos),ty=v,tz=t.substr(tpos+k.size());
                if(sx==tx&&sz==tz)ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
