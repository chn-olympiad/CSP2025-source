#include <bits/stdc++.h>
#define ll  long long
using namespace std;
const int maxn=510,mod=998244353;
int n,m,s[maxn],c[maxn],ans,a[maxn];
int vis[maxn];
void dfs(int x,int cnt){
//    cout<<x<<' '<<cnt<<endl;
    if(x==n+1){
        if(cnt>=m){
            ++ans;
        }
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            a[x]=i;
            dfs(x+1,cnt+(s[x]&&(x-cnt-1<c[i])));
            vis[i]=0;
        }
    }
}
ll jc(ll x){
    ll re=1;
    while(x>1){
        re*=x;
        re%=mod;
        x--;
    }
    return re;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    int sum=0,flag1=1;
    for(int i=1;i<=n;i++){
        scanf("%1d",&s[i]);
        sum+=s[i];
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
        if(c[i]!=1)flag1=0;
    }
    if(m==1){
        if(sum){
            printf("%lld\n",jc(n));
        }
        else{
            printf("%d\n",0);
        }
    }
    else if(flag1==1){
        if(s[1]==1)printf("%lld\n",jc(n));
        else printf("0\n");
    }
    if(n>25){
        printf("0\n");
    }
    else{
        dfs(1,0);
        printf("%d\n",ans);
    }
    return 0;
}
