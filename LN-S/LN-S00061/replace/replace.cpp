#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    pair<string,string>st[n+1];
    string sta,stb;
    for(int i=1;i<=n;i++)
    {
        cin>>st[i].first>>st[i].second;
    }
    while(q--)
    {
        cin>>sta>>stb;
        ans=0;
        if(sta.length()!=stb.length())continue;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<sta.length();j++)
            {
                if(sta[j]==st[i].first[0]&&j+st[i].first.length()<=stb.length())
                {
                    if(sta.substr(0,j)+st[i].second+sta.substr(j+st[i].first.length(),sta.length()-st[i].first.length()-j)==stb)ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}
