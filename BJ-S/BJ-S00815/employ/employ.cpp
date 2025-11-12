#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,dies,a[100010],b[100010];
char c[100010];
void dfs(long long step,long long cnt,long long die,long long f[]){
    if(n-step+1<m-cnt) return;
    if(step>n){
        if(cnt>=m){
            ans++;
            if(ans==998244353) ans=0;
        }
        return;
    }
    for(long long i=1;i<=n;i++){
        if(f[i]==1) continue;
        f[i]=1;
        dfs(step+1,die<a[i]&&c[step]=='1'?cnt+1:cnt,die<a[i]&&c[step]=='1'?die:die+1,f);
        f[i]=0;
    }
    return;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>c[i];
    }
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0) dies++;
    }
    if(n-dies<m){
        cout<<0;
        return 0;
    }
    dfs(1,0,0,b);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
