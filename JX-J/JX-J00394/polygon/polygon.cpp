#include<bits/stdc++.h>
using namespace std;
const int N=5050,mod=998244353;
int n,k,ans;
int a[N],f[N][N];
bool v[N];
void dfs(int s,int dm,int x){
    k++;
    if(k>=70000000)return;
    if(s==dm+1){
        int res=0,ma=0;
        for(int i=1;i<=n;i++){
            if(v[i]==1){
                res+=a[i];
                ma=max(ma,a[i]);
            }
        }
        if(res>ma*2){
                ans++;
                ans=ans%mod;
        }
        return;
    }
    for(int i=x;i<=n;i++){
        if(v[i]==0){
            v[i]=1;
            if(k>=70000000)return;
            dfs(s+1,dm,i);
            v[i]=0;
        }
    }
}
void in(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)f[i][j]=1;
            else f[i][j]=f[i-1][j-1]+f[i-1][j]%mod;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    in();
    bool ff=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)ff=0;
    }
    if(ff==1){
        for(int i=3;i<=n;i++){
            ans=(f[n][i]+ans)%mod;
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++){
        dfs(1,i,1);
        if(k>=70000000)break;
    }
    cout<<ans%mod;
    return 0;
}
