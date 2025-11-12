#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
const int mod=998244353;
typedef unsigned long long ull;
string s[maxn],t[maxn],ask1,ask2;
int n,q;
map<ull,ull> h;
map<ull,int> cnt;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;++i)
    {
        cin>>s[i]>>t[i];
        int l=0,r=s[i].size()-1;
        while(s[i][l]==t[i][l]&&l<s[i].size())l++;
        while(s[i][r]==t[i][r]&&r>=0)r--;
        if(r<l)swap(l,r);
        ull a=0,b=0;
        for(int j=l;j<=r;++j)a=(a*131+s[i][j])%mod,b=(b*131+t[i][j])%mod;
        while(cnt.count(a)&&b!=h[a])a++;
        h[a]=b;
        if(cnt.count(a))cnt[a]=cnt[a]+1;
        else cnt[a]=1;
    }
    for(int i=1;i<=q;++i)
    {
        cin>>ask1>>ask2;
        if(ask1.size()!=ask2.size())
        {
            cout<<0<<endl;
            continue;
        }
        int l=0,r=ask1.size()-1;
        while(ask1[l]==ask2[l]&&l<ask1.size())l++;
        while(ask1[r]==ask2[r]&&r>=0)r--;
        if(r<l)swap(l,r);
        ull a=0,b=0;
        for(int j=l;j<=r;++j)a=(a*131+ask1[j])%mod,b=(b*131+ask2[j])%mod;
        while(cnt.count(a)!=0)
        {
            if(h[a]==b)
            {
                cout<<cnt[a]<<endl;
                break;
            }
            a++;
        }
        if(cnt.count(a)==0)cout<<0<<endl;
    }
    return 0;
}
