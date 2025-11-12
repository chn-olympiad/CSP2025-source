#include<bits/stdc++.h>
using namespace std;
int P=998244353;
int n,ans,sum;
int vis[5001],a[5001];
int dfs(int dep,int m){
    if(dep==m){
        int k=0;
        for(int i=1;i<m;i++){
            if(vis[i]) k+=a[i];
            if(k>a[m]){
                return 1;}
        }
        return 0;
    }
    int x;
    vis[dep]=1;
    x=dfs(dep+1,m)%P;
    vis[dep]=0;
    x=(x+dfs(dep+1,m))%P;
    return x;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a+1,a+n+1);
    if(sum<=n){
        int j=1;
        for(;j<=n;j++){
            if(a[j]) break;
        }j--;
        if(n-j<=2){
            cout<<0;
        }else{
            int k=1;
            for(int i=1;i<=j;i++) k=k*2%P;
            cout<<(n-j-2)*(n-j-1)*(n-j)/6%P*k%P;
        }
        return 0;
    }
    for(int i=1;i<=n;i++) ans=(ans+dfs(1,i))%P;
    cout<<ans;
    return 0;
}
