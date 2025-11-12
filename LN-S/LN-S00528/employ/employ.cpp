#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,m;
string s;
int c[N];
int idx[N];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    s='#'+s;
    for (int i=1;i<=n;i++) cin>>c[i];
    if (n<=12)
    {
        iota(idx+1,idx+1+n,1);
        int ans=0;
        do
        {
            int f=0;
            for (int k=1;k<=n;k++)
            {
                int i=idx[k];
                if (s[k]=='0'||f>=c[i]) f++;
                if (n-f<m) break;
            }
            if (n-f>=m) ans++;
        }
        while (next_permutation(idx+1,idx+1+n));
        cout<<ans<<"\n";
    }
    else if (m==n)
    {
        int zo=0;
        for (int i=1;i<=n;i++) zo+=c[i]==0;
        if (zo) return cout<<0,0;
        if (s.find('0')!=string::npos) return cout<<0,0;
    }
    else if (m==1)
    {
        long long ans=1;
        for (long long i=2;i<=n;i++) ans=ans*i%998244353;
        ans=(ans+998244352)%998244353;
        cout<<ans<<"\n";
    }
    return 0;
}