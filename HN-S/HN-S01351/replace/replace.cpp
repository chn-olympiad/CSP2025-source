#include<bits/stdc++.h>
using namespace std;
const int base=173,mod=998244853,L=2.5e6;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    int n,q;
    cin>>n>>q;
    vector<string>bef(n+1),aft(n+1);
    for(int i=1;i<=n;i++)
        cin>>bef[i]>>aft[i];
    vector<long long>pw(L+1,1);
    for(int i=1;i<=L;i++)
        pw[i]=pw[i-1]*base%mod;
    vector<long long>befh(n+1),afth(n+1);
    for(int i=1;i<=n;i++)
    {
        for(auto ch: bef[i])
            befh[i]=(befh[i]*base+(ch-'a'+1))%mod;
        for(auto ch: aft[i])
            afth[i]=(afth[i]*base+(ch-'a'+1))%mod;
    }
    while(q--)
    {
        string from,to;
        cin>>from>>to;
        if(from.length()!=to.length())
        {
            puts("0");
            continue;
        }
        int m=from.length();
        vector<long long>hsh(m+1);
        for(int i=1;i<=m;i++)
            hsh[i]=(hsh[i-1]*base+(from[i-1]-'a'+1))%mod;
        auto getHsh=[&](const int &l,const int &r)->long long
        {
            return (hsh[r]-1ll*hsh[l-1]*pw[r-l+1]%mod+mod)%mod;
        };
        long long need=0;
        for(int i=1;i<=m;i++)
            need=(need*base+(to[i-1]-'a'+1))%mod;
        int ans=0;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
            {
                int len=bef[j].length();
                if(i+len-1>m)
                    continue;
                long long v=getHsh(i,i+len-1);
                if(v==befh[j])
                {
                    int ed=i+len-1;
                    long long C=pw[m-ed];
                    long long nw=(hsh[m]-v*C%mod+mod+afth[j]*C)%mod;
                    ans+=(nw==need);
                }
            }
        cout<<ans<<'\n';
    }
    
    return 0;
}