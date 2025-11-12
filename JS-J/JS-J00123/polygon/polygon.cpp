#include<bits/stdc++.h>
using namespace std;
int n,a[5001];
long long ans=0;
inline void dfs(int i,int sum,int m){
    if(m+1>=3 and a[i]<sum){
        ans++;
        ans%=998244353;
    }
    if(i+1<=n){
        dfs(i+1,sum+a[i],m+1);
        dfs(i+1,sum,m);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dfs(1,0,0);
    cout<<ans;
    return 0;
}
