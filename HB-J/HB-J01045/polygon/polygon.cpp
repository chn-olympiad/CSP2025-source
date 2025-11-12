#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,a[5050];
bool vis[5050];
long long ans,cnt;
void dfs(int x,int now,long long h,int num){
    if(now==num){
        if(h>a[x]*2){
            cnt=(cnt+1)%mod;
            return;
        }
    }
    for(int i=x+1;i<=n;i++){
        dfs(i,now+1,h+a[i],num);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(&a[1],&a[n]+1);
    for(int i=3;i<=n;i++){
        cnt=0;
        dfs(0,0,0,i);
        ans=(ans+cnt)%mod;
    }
    cout<<ans;
    return 0;
}
