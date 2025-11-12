#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
const int N=1e6+10;
const int base=13331;
const int mod=998244353;
int read()
{
    int w=1,s=0;
    char ch=getchar();
    while(ch<'0'||'9'<ch)
    {
        if(ch=='-') w=-1;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9')
    {
        s=s*10+ch-'0';
        ch=getchar();
    }
    return s*w;
}
int n,m,q;
int pw[N],sum[N];
unordered_map<int,int>vis1;
unordered_map<string,string>vis;
int calc(int l,int r)
{
    return (sum[r]-sum[l]*pw[r-l+1]%mod+mod)%mod;
}
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1) res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return res;
}
void solve()
{
    string s1,s2;
    cin>>s1>>s2;
    m=s1.size();
    s1=" "+s1,s2=" "+s2;
    int posl=n,posr=1,sam=0;
    for(int i=1;i<=m;i++) if(s1[i]!=s2[i]){posl=i;break;}
    for(int i=m;i>=1;i--) if(s1[i]!=s2[i]){posr=i;break;}
    for(int i=1;i<=m;i++) sum[i]=sum[i-1]*base+s1[i]-'a'+1,sam=(sam%base+s2[i]-'a'+1)%mod;
    int cnt=0;
    for(int l=1;l<=posl;l++)
    {
        for(int r=posr;r<=m;r++)
        {
            string ss,res;
            for(int j=l;j<=r;j++) ss+=s1[j];
            for(int j=1;j<l;j++) res+=s1[j];
            res+=vis[ss];
            for(int j=r+1;j<=m;j++) res+=s1[j];
            if((" "+res)==s2) cnt++;
        }
    }
    cout<<cnt<<"\n";
}
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    pw[0]=1;
    for(int i=1;i<=N-10;i++) pw[i]=pw[i-1]*base%mod;
    n=read(),q=read();
    for(int i=1;i<=n;i++)
    {
        string s1,s2;
        cin>>s1>>s2;
        int res1=0,res2=0;
        for(auto v:s1) res1=(res1*base+v-'a'+1)%mod;
        for(auto v:s2) res2=(res2*base+v-'a'+1)%mod;
        vis1[res1]=res2;
        vis[s1]=s2;
    }
    while(q--)
    {
        solve();
    }
}
