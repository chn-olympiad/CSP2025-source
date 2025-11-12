#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e6+10,seed=97,mod=1e9+7;

int n,q;

string S1[200010],S2[200010],T1[200010],T2[200010];

int sh1[200010],sh2[200010];

int difS[200010],difT[200010],powseed[N];

int powmod(int x,int y)
{
    int ans=1,p=x;
    while (y)
    {
        if (y & 1) ans=1ll*ans*p%mod;
        p=1ll*p*p%mod;
        y>>=1;
    }
    return ans;
}

namespace Sub1{

    int h[3][1010][2010];

    int tak(int t,int i,int l,int r)
    {
        if (l>r) return 0;
        int ans=h[t][i][r]-h[t][i][l-1]*powseed[r-l+1]%mod;
        if (ans<0) ans+=mod;
        return ans;
    }

    void solve()
    {
        for (int i=1;i<=q;i++)
        {
            h[1][i][0]=1;
            for (int j=1;j<=T1[i].size()-1;j++) h[1][i][j]=(h[1][i][j-1]*seed+(T1[i][j]-'a'))%mod;
            h[2][i][0]=1;
            for (int j=1;j<=T2[i].size()-1;j++) h[2][i][j]=(h[2][i][j-1]*seed+(T2[i][j]-'a'))%mod;
        }

        for (int opt=1;opt<=q;opt++)
        {
            int ans=0;
            for (int i=1;i<=n;i++)
            {
                if (difS[i]==0) continue;
                int l=difT[opt]-difS[i]+1,r=difT[opt]-difS[i]+1+S1[i].size()-1-1; 
                if (r>T1[opt].size()-1) continue;
                if (l<1) continue;   //cout<<opt<<" "<<i<<" "<<l<<" "<<r<<"|"<<endl;//cout<<sh1[i]<<" "<<tak(1,opt,l,r)<<endl;
                if (sh1[i]!=tak(1,opt,l,r)) continue;//cout<<opt<<" "<<i<<" "<<l<<" "<<r<<endl;
                if (sh2[i]!=tak(2,opt,l,r)) continue;//cout<<opt<<" "<<i<<" "<<l<<" "<<r<<endl;
                if (tak(1,opt,r+1,T1[opt].size()-1)!=tak(2,opt,r+1,T1[opt].size()-1)) continue;//cout<<opt<<" "<<i<<" "<<l<<" "<<r<<endl;
                ans++;
            }
            printf("%lld\n",ans);
        }


        // for (int i=1;i<=n;i++) cout<<difS[i]<<" ";cout<<endl;
        // for (int i=1;i<=q;i++) cout<<difT[i]<<" ";cout<<endl;
    }
}

namespace Sub2{

    int h[2][N];

    int tak(int t,int i,int l,int r)
    {
        if (l>r) return 0;
        int ans=h[t-1][r]-h[t-1][l-1]*powseed[r-l+1]%mod;
        if (ans<0) ans+=mod;
        return ans;
    }

    void solve()
    {
        for (int i=1;i<=q;i++)
        {
            h[0][0]=1;
            for (int j=1;j<=T1[i].size()-1;j++) h[0][j]=(h[0][j-1]*seed+(T1[i][j]-'a'))%mod;
            h[1][0]=1;
            for (int j=1;j<=T2[i].size()-1;j++) h[1][j]=(h[1][j-1]*seed+(T2[i][j]-'a'))%mod;
        }
        for (int opt=1;opt<=q;opt++)
        {
            int ans=0;
            for (int i=1;i<=n;i++)
            {
                if (difS[i]==0) continue;
                int l=difT[opt]-difS[i]+1,r=difT[opt]-difS[i]+1+S1[i].size()-1-1; 
                if (r>T1[opt].size()-1) continue;
                if (l<1) continue;
                if (sh1[i]!=tak(1,opt,l,r)) continue;//cout<<"|"<<l<<" "<<r<<endl;
                if (sh2[i]!=tak(2,opt,l,r)) continue;//cout<<l<<" "<<r<<endl;
                if (tak(1,opt,r+1,T1[opt].size()-1)!=tak(2,opt,r+1,T1[opt].size()-1)) continue;//cout<<l<<" "<<r<<endl;
                ans++;
            }
            printf("%lld\n",ans);
        }
    }
}

signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    powseed[0]=1;
    for (int i=1;i<=N-10;i++) powseed[i]=(powseed[i-1]*seed)%mod;

    scanf("%lld %lld",&n,&q);
    for (int i=1;i<=n;i++) cin>>S1[i]>>S2[i];
    for (int i=1;i<=n;i++) S1[i]=" "+S1[i],S2[i]=" "+S2[i];
    for (int i=1;i<=q;i++) cin>>T1[i]>>T2[i];
    for (int i=1;i<=n;i++) T1[i]=" "+T1[i],T2[i]=" "+T2[i];
    
    for (int i=1;i<=n;i++) for (int j=1;j<=S1[i].size()-1;j++) if (S1[i][j]!=S2[i][j]){difS[i]=j;break;}
    for (int i=1;i<=n;i++) for (int j=1;j<=T1[i].size()-1;j++) if (T1[i][j]!=T2[i][j]){difT[i]=j;break;}

    for (int i=1;i<=n;i++)
    {
        int hs=1;
        for (int j=1;j<=S1[i].size()-1;j++) hs=(hs*seed+(S1[i][j]-'a'))%mod;
        sh1[i]=hs-powseed[S1[i].size()-1];if (sh1[i]<0) sh1[i]+=mod;
        hs=1;
        for (int j=1;j<=S2[i].size()-1;j++) hs=(hs*seed+(S2[i][j]-'a'))%mod;
        sh2[i]=hs-powseed[S2[i].size()-1];if (sh2[i]<0) sh2[i]+=mod;
    }

    if (q==1) Sub2::solve();
    else Sub1::solve();

    return 0;
}