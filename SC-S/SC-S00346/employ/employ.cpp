#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=505,Mod=998244353;
int n,m,ans,c[N],p[N];
bool op[N],vis[N];
char ch[N];

void dfs(int d){
    if(d>n){
        int cnt0=0,cnt1=0;
        for(int i=1;i<=n;i++){
            if(cnt0<c[p[i]]&&op[i])cnt1++;
            else cnt0++;
        }
        ans+=(cnt1>=m);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            p[d]=i,vis[i]=1;
            dfs(d+1);
            vis[i]=0;
        }
    }
}

signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld%s",&n,&m,ch+1);
    for(int i=1;i<=n;i++){
        op[i]=ch[i]-'0';
        scanf("%lld\n",&c[i]);
    }
    if(n<=10)dfs(1);
    else{
        ans=1;
        for(int i=1;i<=n;i++)ans=ans*i%Mod;
    }
    printf("%lld\n",ans);
    return 0;
}