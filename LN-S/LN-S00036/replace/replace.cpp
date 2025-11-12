#include <iostream>
#define int long long
const int N=2e5+5,M=5e6+5,mod=660658993,P=1331;
int n,Q,cnt,pw[M],sz[N],hs1[N],hs2[N],h1[M],h2[M];
int hsh(int *h,int l,int r) {return (h[r]-(l?h[l-1]:0)*pw[r-l+1]%mod+mod)%mod;}
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    std::cin.tie(0)->sync_with_stdio(0);
    std::cin>>n>>Q;
    pw[0]=1;
    for(int i=1;i<M;i++) pw[i]=pw[i-1]*P%mod;
    std::string s1,s2;
    for(int i=1;i<=n;i++)
    {
        std::cin>>s1>>s2;
        sz[i]=s1.size();
        for(int j=0;j<sz[i];j++)
            hs1[i]=(hs1[i]*P+s1[j])%mod,
            hs2[i]=(hs2[i]*P+s2[j])%mod;
    }
    for(int i=1;i<=Q;i++)
    {
        std::cin>>s1>>s2;
        if(s1.size()!=s2.size()) {std::cout<<"0\n";continue;}
        int p1=s1.size(),p2=-1;
        for(int j=0;j<s1.size();j++) if(s1[j]!=s2[j]) {p1=j;break;}
        for(int j=s1.size()-1;j>=0;j--) if(s1[j]!=s2[j]) {p2=j;break;}
        for(int j=0;j<s1.size();j++)
            h1[j]=((j?h1[j-1]:0)*P+s1[j])%mod,
            h2[j]=((j?h2[j-1]:0)*P+s2[j])%mod;
        int ans=0;
        for(int j=1;j<=n;j++)
            for(int k=0;k+sz[j]-1<s1.size()&&k<=p1;k++) if(k+sz[j]-1>=p2)
            {
                if(hsh(h1,k,k+sz[j]-1)==hs1[j]&&hsh(h2,k,k+sz[j]-1)==hs2[j])
                    ans++;
            }
        std::cout<<ans<<'\n';
    }
}