#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;
const int N=2e3+5,mod=1145142023,base=31,Mx=2e3;
int n,q,len,hsh1,hsh2,fb[N],hs1[N],hs2[N],ans,t1,t2;
char s1[N],s2[N];
map <int,int> mp;
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    faster;
    cin >> n >> q;
    fb[0]=1;
    for(int i=1;i<=Mx;i++)
    {
        fb[i]=fb[i-1]*base%mod;
    }
    for(int i=1;i<=n;i++)
    {
        cin >> s1+1 >> s2+1;
        len=strlen(s1+1);
        hsh1=hsh2=0;
        for(int j=1;j<=len;j++)
        {
            hsh1=(hsh1*base+(s1[j]-'a'+1))%mod;
        }
        for(int j=1;j<=len;j++)
        {
            hsh2=(hsh2*base+(s2[j]-'a'+1))%mod;
        }
        mp[hsh1<<31|hsh2]++;
        // cout << hsh1 <<' '<< hsh2 <<'\n';
    }
    while(q--)
    {
        cin >> s1+1 >> s2+1;
        ans=0;
        len=strlen(s1+1);
        hs1[0]=0;
        for(int i=1;i<=len;i++)
        {
            hs1[i]=(hs1[i-1]*base+(s1[i]-'a'+1))%mod;
        }
        hs2[0]=0;
        for(int i=1;i<=len;i++)
        {
            hs2[i]=(hs2[i-1]*base+(s2[i]-'a'+1))%mod;
        }
        for(int i=0;i<=len;i++)
        {
            if(s1[i]!=s2[i])break;
            for(int j=len+1;j>=i+2;j--)
            {
                if(s1[j]!=s2[j])break;
                t1=(hs1[j-1]-hs1[i]*fb[j-i-1]%mod+mod)%mod;
                t2=(hs2[j-1]-hs2[i]*fb[j-i-1]%mod+mod)%mod;
                // cout <<"q:"<< i <<' '<< j <<' '<< t1 <<' '<< t2 <<'\n';
                ans+=mp[t1<<31|t2];
            }
        }
        cout << ans <<'\n';
    }
    return 0;
}