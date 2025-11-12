#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
struct st{
    string fr,to;
    ll len;
}k[200005];
void solve()
{
    ll ans=0;
    string s,t;
    cin>>s>>t;
    for(ll i=0;i<s.size();i++)
    {
        for(ll j=1;j<=n;j++)
        {
            string x="",y="";
            for(ll z=i;z<s.size()&&z<i+k[j].len;z++)
            {
                x+=s[z];
                y+=t[z];
                if(k[j].fr[z-i]!=s[z]||k[j].to[z-i]!=t[z])break;
            }
            if(x==k[j].fr&&y==k[j].to)
            {
                string yy=s;
                for(ll z=i;z<s.size()&&z<i+k[j].len;z++)
                {
                    yy[z]=t[z];
                }
                if(yy==t)ans++;
            }
        }
    }
    cout<<ans<<endl;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ll q;
    cin>>n>>q;
    for(ll i=1;i<=n;i++)
    {
        cin>>k[i].fr>>k[i].to;
        k[i].len=k[i].fr.size();
    }
    while(q--)solve();
    return 0;
}


