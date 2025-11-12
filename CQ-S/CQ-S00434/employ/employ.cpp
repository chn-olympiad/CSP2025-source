#include<bits/stdc++.h>
using namespace std;
namespace SOLUTION{
    constexpr int maxn=503,mod=998244353;typedef long long ll;
    bool vis[maxn];int patient[maxn],n,m,ans;char str[maxn];
    inline void calc(int step,int count){
        if(step>=n){ans+=count>=m;return;}
        for(int i=1;i<=n;++i)if(!vis[i])vis[i]=true,
            calc(step+1,count+(str[step]=='1'&&step-count<patient[i])),vis[i]=false;
    }
    inline int Main(){
        cin>>n>>m>>str;for(int i=1,c;i<=n;++i)cin>>patient[i];
        calc(0,0),cout<<ans<<'\n';return 0;
    }
}
int main(){freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    SOLUTION::Main();return 0;
}