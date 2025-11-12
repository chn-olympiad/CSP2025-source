#include <bits/stdc++.h>
using namespace std;
int n,a[5001];
long long ans=0;
void dfs(int x,int y,int j,int m){
    if(m>=3&&x>y*2)ans++;
    ans%=998244353;
    for(int i=j;i<=n;i++){
        dfs(x+a[i],max(y,a[i]),i+1,m+1);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n-2;i++){
        dfs(a[i],a[i],i+1,1);
    }
    cout<<ans;
    return 0;
}
//bu hui 555
