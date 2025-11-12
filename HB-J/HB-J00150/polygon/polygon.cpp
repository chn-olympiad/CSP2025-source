#include <iostream>
#include <cstdio>
using namespace std;
int a[5009],n,sum=0,maxn=-1,ans=0;
void dfs(int l,int q){
    if(l==0 && sum>(maxn*2)){
        ans++;
        ans=ans%998244353;
        return ;
    }
    for(int i=q;i<=n;i++){
        sum+=a[i];
        maxn=max(maxn,a[i]);
        dfs(l-1,i+1);
        sum=0,maxn=-1;
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=3;i<=n;i++){
        dfs(i,1);
    }
    cout << ans;
    return 0;
}
