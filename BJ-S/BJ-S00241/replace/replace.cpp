#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q;
string s[200005][2];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>s[i][1]>>s[i][2];
    while(q--)
    {
        ll l=-1,r=-1,ans=0;
        string t1,t2,dif1="",dif2="";
        cin>>t1>>t2;
        if(t1.size()!=t2.size())
        {
            cout<<0<<'\n';
            continue;
        }
        for(int i=0;i<t1.size();i++)
        {
            if(l==-1&&t1[i]!=t2[i])
                l=i;
            if(l!=-1&&t1[i]==t2[i])
                r=i-1;
        }
        if(l==-1)
            l=0;
        if(r==-1)
            r=t1.size()-1;
        for(int i=l;i<=r;i++)
        {
            dif1+=t1[i];
            dif2+=t2[i];
        }
        for(int i=1;i<=n;i++)
        {
            ll xa=s[i][1].find(dif1);
            ll xb=s[i][2].find(dif2);
            if(xa!=string::npos&&xa==xb&&t1.find(s[i][1])!=string::npos&&t1.find(s[i][1])==t2.find(s[i][2]))
                ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
