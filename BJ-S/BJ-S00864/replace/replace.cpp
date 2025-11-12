#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[200005][3];
ll n,q,ii[200005][3][3],bb[200005][3],ans;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(ll i=1;i<=n;i++)
    {
        cin>>s[i][1]>>s[i][2];
        for(ll j=0;j<s[i][1].size();j++)
        {
            if(s[i][1][j]=='b')
            {
                bb[i][1]=j;
                ii[i][1][1]=j-1;ii[i][1][2]=s[i][1].size()-1-j;
            }
        }
        for(ll j=0;j<s[i][2].size();j++)
        {
            if(s[i][2][j]=='b')
            {
                bb[i][2]=j;
                ii[i][2][1]=j-1;ii[i][2][2]=s[i][2].size()-1-j;
            }
        }
    }
    while(q--)
    {
        ans=0;
        string t1,t2;
        cin>>t1>>t2;
        ll i1,i2,i3,i4,b1,b2;
        for(ll i=1;i<t1.size();i++)
        {
            if(t1[i]=='b')
            {
                b1=i;
                i1=i-1;i2=t1.size()-1-i;
                break;
            }
        }
        for(ll i=1;i<t2.size();i++)
        {
            if(t2[i]=='b')
            {
                b2=i;
                i3=i-1;i4=t2.size()-1-i;
                break;
            }
        }
        if(t1.size()!=t2.size())
        {
            cout<<0;
            continue;
        }
        else
        {
            ll iu=i2-i1;
            for(ll i=1;i<=n;i++)
            {
                ll bu=bb[i][1]-bb[i][2];
                if(ii[i][1][1]<=i1&&ii[i][1][2]<=i2&&ii[i][2][1]<=i3&&ii[i][2][2]<=i4&&iu==bu)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
}
