#include<iostream>
#include<cstdio>
using namespace std;
int n,maxn,f[5005],a[5005],ans;
void dfs(int x,int h,int m,int cnt){
    if(h+f[n]-f[x-1]<=m*2)return;
    if(x==n+1){
        if(h>m*2&&cnt>=3){
            ans++;
            ans%=998244353;
        }
        return;
    }
    dfs(x+1,h+a[x],max(m,a[x]),cnt+1);
    dfs(x+1,h,m,cnt);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(maxn==1){
        for(int i=4;i<=n;i++){
            int p=1;
            for(int j=0;j<i;j++){
                p*=(n-j);
                p%=998244353;
            }
            for(int j=2;j<=i;j++){
                p/=j;
            }
            ans+=p;
            ans%=998244353;
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++){
        f[i]=f[i-1]+a[i];
    }
    dfs(1,0,0,0);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
