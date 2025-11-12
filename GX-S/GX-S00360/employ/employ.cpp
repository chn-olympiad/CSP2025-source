#include<bits/stdc++.h>
using namespace std;

const long long mod=998244353;
int n,m;
int c[510];
bool s[510];
int p[510];
bool vis[510];
long long as;
bool rdb(){
    char in=getchar();
    while(in<'0' || in>'1') in=getchar();
    return in-'0';
}
int rd(){
    int t=0;
    char in=getchar();
    while(in<'0' || in>'9') in=getchar();
    while(in>='0' && in<='9'){
        t = t*10+(in-'0');
        in = getchar();
    }
    return t;
}
void dfs(int now){
    if(now >= n+1){
        int cb=0,f=0;
        for(int i=1;i<=n;i++){
            if(cb<c[p[i]] && s[i]==1){
                f++;
            }
            else cb++;
        }
        if(f >= m) as++;
        as %= mod;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i] = 1;
            p[now] = i;
            dfs(now+1);
            vis[i] = 0;
        }
    }
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        s[i] = rdb();
    }
    for(int i=1;i<=n;i++){
        c[i] = rd();
    }
    dfs(1);
    printf("%lld\n",as);
    return 0;
}
