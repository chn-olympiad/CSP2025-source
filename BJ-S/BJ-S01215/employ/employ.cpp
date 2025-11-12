#include<bits/stdc++.h>
using namespace std;
const long long P=998244353;
char eoh[550];
int n,m,c[550],ls[550];
long long ans;
bool vis[550];
bool check(){
    int sum=n-m,cnt=0;
    for(int i=1;i<=n;i++){
        //cout<<ls[i]<<" ";
        if(eoh[i]=='0'||cnt>=ls[i]) cnt++;
        if(cnt>sum) return 0;
    }
    return 1;
}
void dfs(int step){
    if(step==n+1){
        if(check()) ans=(ans+1)%P;
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        vis[i]=1;
        ls[step]=c[i];
        dfs(step+1);
        vis[i]=0;
    }
    return;
}
long long qpl(int x){
    long long num=2;
    for(x;x>2;x--){
        num=(num*x)%P;
    }
    return num;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    int pf=0,pf2=0;
    for(int i=1;i<=n;i++){
        cin>>eoh[i];
        if(eoh[i]=='1') pf++;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
        if(c[i]!=0) pf2++;
    }
    if(m==n){
        if(pf!=n||pf2!=n) printf("0");
        else printf("%lld",qpl(pf2));
        return 0;
    }
    if(pf==n&&pf2==n){
        printf("%lld",qpl(n));
        return 0;
    }
    if(m==1){
        printf("%lld",qpl(n));
        return 0;
    }
    dfs(1);
    printf("%lld",ans);
    return 0;
}
