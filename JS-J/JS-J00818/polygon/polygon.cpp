#include<bits/stdc++.h>
using namespace std;
int n,a[5009];
long long ans;
void dfs(int step,int maxx,long long sum,int m){
    if(2*maxx<sum&&m>=3)
        ans++;
    if(step>n){
        return;
    }
    for(int i=step;i<=n;++i){
        dfs(i+1,max(maxx,a[i]),sum+a[i],m+1);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    dfs(1,0,0,0);
    cout<<ans%998244353;
    return 0;
}
