#include<bits/stdc++.h>
using namespace std;
map<string,pair<string,int> >mp;
int cc[200005];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        string a,b;
        cin>>a>>b;
        mp[a]={b,i};
    }
    while(q--)
    {
        string u,v;
        cin>>u>>v;
        long long ans=0;
        int l=0;
        for(int i=0;i<u.size();i++)
        {
            if(u[i]!=v[i])break;
            l++;
        }
        int r=u.size()-1;
        for(;r>=0;r--)
        {
            if(u[r]!=v[r])break;
        }
        // cout<<l<<' '<<r<<endl;
        // if(l<=r)
        {
            // cout<<u.substr(0,5)<<endl;
            // for(int i=0;i<=l;i++)
            // {
            //     for(int len=r-i;l+len-2<u.size();len++)
            //     {
                    
            //     }
            // }
            for(int i=0;i<u.size();i++)
            {
                for(int len=1;i+len-1<u.size();len++)
                {
                    int lr=i+len-1;
                    // cout<<i<<' '<<len<<endl;
                    if(lr<r||i>l)continue;
                    string now=u.substr(i,len);
                    auto to=mp[now];
                    // cout<<to.first<<' '<<v.substr(i,len)<<endl;
                    if(to.first==v.substr(i,len))
                    {
                        if(cc[to.second]!=q+1)ans++;
                        cc[to.second]=q+1;
                        // cout<<to.second<<endl;
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
