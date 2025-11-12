#include <bits/stdc++.h>
using namespace std;
int n,res;
int a[5005];
void dfs(int stick,int length,int mmax,int cnt){
    for(int i=stick+1;i<=n;i++){
        dfs(i,length+a[i],max(mmax,a[i]),cnt+1);
    }
    if(cnt>=3&&length>mmax*2){
        res=(res+1)%998244353;
        return ;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        dfs(i,a[i],a[i],1);
    }
    cout<<res%998244353;
    return 0;
}
