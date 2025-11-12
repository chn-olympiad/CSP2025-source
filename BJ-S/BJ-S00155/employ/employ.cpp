#include<bits/stdc++.h>
#define int long long
using namespace std;

bool s[505];
int a[505],cnt,c[505];
bool b[505];
int n,m,ans=1;
const int mod=998244353;

void dfs(const int x){
    if(x==n){
        cnt=0;
        for(int i=1;i<=n;++i){
            if(a[c[i]]<=cnt) cnt++;
            else if(!s[i]) cnt++;
        }
        if(n-cnt>=m) ans++;
        return;
    }
    for(int i=1;i<=n;++i){
        if(b[i])continue;
        b[i]=1;
        c[x+1]=i;
        dfs(x+1);
        c[x+1]=0;
        b[i]=0;
    }
    return;
}

signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    bool fl=1;
    for(int i=1;i<=n;++i){
        char c;
        cin>>c;
        s[i]=(c^48);
        fl&=s[i];
    }
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    if(fl){
        for(int i=1;i<=n;++i){
            ans*=i;
            ans%=mod;
        }
        cout<<ans<<"\n";
        return 0;
    }
    ans=0;
    dfs(0);
    cout<<ans;
    return 0;
}
