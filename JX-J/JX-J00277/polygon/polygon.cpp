#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5100],ans;
void dfs(int cnt,int pos,int ma,int x){
    if(x==0){
        if(ma*2<cnt) ans++;
        return ;
    }
    for(int i=pos;i<=n;i++){
        dfs(cnt+a[i],i+1,max(ma,a[i]),x-1);
    }
}
int main(){
//    freopen("polygon.in","r",stdin);
//    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    if(a[n]==1){
        for(int i=3;i<=n;i++){
            ans=(ans+(((n-i+2)%mod*(n-i+1)%mod)/(2%mod))%mod)%mod;
        }
        cout<<ans%mod;
    }
    else{
        for(int i=3;i<=n;i++){
            for(int j=1;j<=n-i+1;j++){
                dfs(0,j,0,i);
            }
        }
        cout<<ans%mod;
    }
    return 0;
}
