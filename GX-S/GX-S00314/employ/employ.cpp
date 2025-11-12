#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510,P=998244353;


char s[N];
int n,m,c[N],xl[N],vis[N];
ll ans;

void dfs(int dep){
    if(dep>n){
        int cnt=0, num=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='0'){cnt++; continue;}
            if(cnt>=c[xl[i]]){cnt++; continue;}
            num++;
        }
        if(num>=m)ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        xl[dep]=i; vis[i]=1;
        dfs(dep+1);
        vis[i]=0;
    }
}


int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)scanf("%d",&c[i]);

    if(m==n){
        int flag=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='0')flag=1;
            if(!c[i])flag=1;
        }
        if(flag)puts("0");
        else{
            ans=1;
            for(int i=1;i<=n;i++)ans=ans*i%P;
            printf("%lld",ans);
        }
        return 0;
    }

    dfs(1);
    printf("%lld",ans%P);
    return 0;
}
