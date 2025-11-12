#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,q;
map<pair<string,string>,int>cnt;
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        string x,y;
        cin>>x>>y;
        cnt[make_pair(x,y)]++;
    }
    while(q--)
    {
        string x,y;
        ll ans=0;
        cin>>x>>y;
        int r=x.size()-1;
        while(x[r]==y[r])r--;
        for(int i=0;i<x.size();i++)
        {
            string t1="",t2="";
            for(int j=i;j<x.size();j++)
            {
                t1+=x[j],t2+=y[j];
                if(j>=r&&cnt.find(make_pair(t1,t2))!=cnt.end())ans+=cnt[make_pair(t1,t2)];
            }
            if(x[i]!=y[i])break;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
