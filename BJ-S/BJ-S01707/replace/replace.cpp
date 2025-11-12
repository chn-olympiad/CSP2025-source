#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,q;
pair<string,string> p[200010];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(ll i=1;i<=n;i++)
        cin>>p[i].first>>p[i].second;
    for(ll k=1;k<=q;k++)
    {
        ll cnt=0;
        string a,b;
        cin>>a>>b;
        for(ll i=1;i<=n;i++)
        {
            if(a.size()<p[i].first.size())continue;
            for(ll j=0;j<=a.size()-p[i].first.size();j++)
            {
                if(a.substr(j,p[i].first.size())==p[i].first)
                {
                    string t=a.substr(0,j);
                    t=t+p[i].second;
                    t=t+a.substr(j+p[i].first.size(),a.size()-(j+p[i].first.size()));
                    if(t==b)
                        cnt++;
                }
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
