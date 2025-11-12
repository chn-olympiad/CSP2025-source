#include <bits/stdc++.h>
using namespace std;
int a[5005],n;
long long ans;
#define N 998244353
void dfs(int i,int h,int m,long long sum){
    if(i>n){
        if(sum>m*2&&h>=3){
            ans=(ans+1)%N;
        }
        return;
    }
    dfs(i+1,h+1,max(m,a[i]),sum+a[i]);
    dfs(i+1,h,m,sum);
}
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0,0,0);
    cout<<ans;
    return 0;
}
