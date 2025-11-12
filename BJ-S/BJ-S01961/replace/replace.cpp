#include<bits/stdc++.h>
namespace akioi
{
    using namespace std;
    #define F(i,x,y) for(i=x;i<=y;i++)
    #define rF(i,x,y) for(i=x;i>=y;i--)
    //#define int long long
    void cout_better()
    {
        ios::sync_with_stdio(0);
        cout.tie(0),cin.tie(0);
        return;
    }
    const int N=2e5+5;
}
using namespace akioi;
int n,q,df[3005],f1[3005],f2[3005];
string s[N][2];
void solve1()
{
    string t[2];
    int i,j,k,ans=0;
    while(q--)
    {
        cin>>t[0]>>t[1];
        ans=0;
        if(t[0].size()!=t[1].size()) {cout<<"0\n";continue;}
        F(i,1,t[0].size()) df[i]=df[i-1]+(t[0][i-1]!=t[1][i-1]);
        df[i]=df[i-1];
        F(i,1,n)
        {
            int ls=s[i][0].size(),tn=ls+t[0].size()+1;
            string tmp1=' '+s[i][0]+'#'+t[0],tmp2=' '+s[i][1]+'#'+t[1];
            F(j,2,tn) 
            {
                k=f1[j-1];
                while(tmp1[k+1]!=tmp1[j]&&k!=0) k=f1[k];
                f1[j]=(k==0&&tmp1[k+1]!=tmp1[j]?0:k+1);
            }
            F(j,2,tn) 
            {
                k=f2[j-1];
                while(tmp2[k+1]!=tmp2[j]&&k!=0) k=f2[k];
                f2[j]=(k==0&&tmp2[k+1]!=tmp2[j]?0:k+1);
            }
            F(j,2*ls+1,tn) if(f1[j]==ls&&f2[j]==ls&&df[j-2*ls-1]==0&&df[j-ls-1]==df[t[0].size()]) ans++;
        }
        cout<<ans<<'\n';
    }
}
void solve()
{
    cin>>n>>q;
    int sum=0;
    int i;
    F(i,1,n) cin>>s[i][0]>>s[i][1],sum+=2*s[i][0].size();
    if(sum<=2500&&n<=1020&&q<=1020) solve1();
    //else solve2();
    return;
}
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cout_better();
    int T=1;
    //cin>>T;
    while(T--) solve();
}