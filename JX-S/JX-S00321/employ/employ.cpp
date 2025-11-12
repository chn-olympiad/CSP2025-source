#include<bits/stdc++.h>
#define CSP2025 using
#define RP namespace
#define plusplus std
CSP2025 RP plusplus;
using ll=long long;
//#define int long long
#define piii pair<int,pair<int,int> >
#define mp(x,y,z) make_pair(x,make_pair(y,z))
inline int rd(){int x=0,f=1;char ch=getchar();for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);return x*f;}
constexpr int N=505,mod=998244353;
int n,m,s[N],c[N],seq[N],ans=0;
bitset<N>vis;
void dfs(int lyr,int LYR,int nw,int cnt){
    if(lyr>LYR){
        if(cnt>=m){
            //for(int i=1;i<=LYR;++i)cout<<seq[i]<<" \n"[i==LYR];
            ans=(ans+1)%mod;
        }
    }else{
        for(int i=1;i<=n;++i)if(!vis[i]){
            vis[i]=1;seq[lyr]=i;
            if(nw>=c[i]||s[lyr]==0)dfs(lyr+1,LYR,nw+1,cnt);
            else dfs(lyr+1,LYR,nw,cnt+1);
            vis[i]=0;
        }
    }
}signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    n=rd(),m=rd();int _1cnt=0;
    string str;cin>>str;
    for(int i=1;i<=n;++i)c[i]=rd(),_1cnt+=(s[i]=(str[i-1]=='1'));
    if(n<=18)dfs(1,n,0,0);
    else if(_1cnt==n){
        ans=1;
        for(int i=1;i<=n;++i)ans=ans*i%mod;
    }
    cout<<ans<<'\n';
}
