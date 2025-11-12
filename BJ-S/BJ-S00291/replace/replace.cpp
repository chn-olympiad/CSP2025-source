#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
const int base=131;
const int MOD=1e9+7;
int n,q; string s1,s2;
unordered_map <int,unordered_map<int,int> > mp;
int hs1[N],hs2[N],pw[N],p[N],len[N];
int ha1[N],ha2[N];

signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>q;
    pw[0]=1; for (int i=1;i<N;i++) pw[i]=pw[i-1]*base%MOD;
    for (int i=1;i<=n;i++)
    {
        cin>>s1>>s2;
        int Ha1=0,Ha2=0;
        for (int j=0;s1[j]!='\0';j++) Ha1=(Ha1*base%MOD+s1[j]-'a'+1)%MOD;
        for (int j=0;s2[j]!='\0';j++) Ha2=(Ha2*base%MOD+s2[j]-'a'+1)%MOD;
        mp[Ha1][Ha2]++; ha1[i]=Ha1,ha2[i]=Ha2;
        for (int j=0;s1[j]!='\0';j++) if (s1[j]!=s2[j]) { p[i]=j+1; break; }
        len[i]=s1.size();
    }
    if (q==1)
    {
        cin>>s1>>s2; s1=" "+s1,s2=" "+s2;
        if (s1.size()!=s2.size()) { cout<<"0\n"; return 0; }
        int pre,lst;
        for (int j=1;s1[j]!='\0';j++) if (s1[j]!=s2[j]) { pre=j; break; }
        for (int j=s1.size()-1;j>=1;j--) if (s1[j]!=s2[j]) { lst=j; break; }
        for (int j=1;s1[j]!='\0';j++) hs1[j]=(hs1[j-1]*base%MOD+s1[j]-'a'+1)%MOD;
        for (int j=1;s2[j]!='\0';j++) hs2[j]=(hs2[j-1]*base%MOD+s2[j]-'a'+1)%MOD;

        int ans=0;
        for (int i=1;i<=n;i++)
        {
            int j=pre+len[i]-p[i],k=j-len[i]+1;
            if (j<lst||k>pre) continue;
            if (k>=1&&j<s1.size()&&(hs1[j]-hs1[k-1]*pw[j-k+1]%MOD+MOD)%MOD==ha1[i]&&(hs2[j]-hs2[k-1]*pw[j-k+1]%MOD+MOD)%MOD==ha2[i]) ans++;
        }
        cout<<ans<<"\n"; return 0;
    }
    for (int i=1;i<=q;i++)
    {
        cin>>s1>>s2; s1=" "+s1,s2=" "+s2; int ans=0;
        if (s1.size()!=s2.size()) { cout<<"0\n"; continue; }
        int pre,lst;
        for (int j=1;s1[j]!='\0';j++) if (s1[j]!=s2[j]) { pre=j; break; }
        for (int j=s1.size()-1;j>=1;j--) if (s1[j]!=s2[j]) { lst=j; break; }
        for (int j=1;s1[j]!='\0';j++) hs1[j]=(hs1[j-1]*base%MOD+s1[j]-'a'+1)%MOD;
        for (int j=1;s2[j]!='\0';j++) hs2[j]=(hs2[j-1]*base%MOD+s2[j]-'a'+1)%MOD;
        
        for (int j=lst;s1[j]!='\0';j++)
        for (int k=1;k<=pre;k++) ans+=mp[(hs1[j]-hs1[k-1]*pw[j-k+1]%MOD+MOD)%MOD][(hs2[j]-hs2[k-1]*pw[j-k+1]%MOD+MOD)%MOD];
        cout<<ans<<"\n";
    }
    return 0;
}