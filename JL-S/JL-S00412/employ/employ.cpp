#include<bits/stdc++.h>
#define mod 998244353
#define maxn 501
using namespace std;
int n,m,p[maxn],q[maxn];
char s[maxn],c[maxn];
bool flag[maxn];
long long ans;
void dfs(int day,int person,int loser,int cnt){
    // cout<<person<<'\n';
    if(flag[person])return;
    flag[person]=1;
    if(p[person]<=loser||q[day]==0){
        // cout<<"get\n";
        for(int i=1;i<=n;i++){
            if(flag[i])continue;
            dfs(day+1,i,loser+1,cnt);
        }
    }else{
        // cout<<"coin\n";
        cnt+=1;
         for(int i=1;i<=n;i++){
            if(flag[i])continue;
            dfs(day+1,i,loser,cnt);
         }
    }
    flag[person]=0;
    if(day==n){
        // cout<<day<<' '<<person<<'\n';
        if(cnt>=m){
            ans++;
        }
    }
    return;
}
void plan_A(){
    for(int i=1;i<=n;i++){
        dfs(1,i,0,0);
    }
    return;
}
void plan_B(){
    int ddl;
    for(int i=1;i<=n;i++){
        if(q[i]==1){
            ddl=i;
            break;
        }
    }
    // cout<<"ddl "<<ddl<<endl;
    int zeta=0;
    for(int i=1;i<=n;i++){
        // cout<<p[i]<<endl;
        if(p[i]>=ddl){
            zeta++;
            // cout<<zeta<<endl;
        }
    }
    ans=1;
    while(zeta){
        ans*=zeta--;
    }
    return;
}
void plan_C(){
    ans=1;
    for(int i=1;i<=n;i++){
        if(q[i]==0){
            ans=0;
            break;
        }
    }
    return;
}
bool if_plan_D(){
    bool axiz=1;
    for(int i=1;i<=n;i++){
        if(q[i]==0){
            axiz=0;
            break;
        }
    }
    return axiz;
}
void plan_D(){
    ans=1;
    while(n){
        ans*=n--;
        // cout<<ans<<endl;
    }
    return;
}
int main(){
    freopen ("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    // cout<<s<<"\n";
    for(int i=1;i<=n;i++){
        q[i]=int(s[i-1]-'0');
        scanf("%d",&p[i]);
        // cout<<q[i]<<' ';
    }
    if(n<=18){
        plan_A();
    }else if(m==1){
        plan_B();
    }else if(n==m){
        plan_C();
    }else if(if_plan_D()){
        plan_D();
    }
    ans%=mod;
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}