#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[10010],INF=998244353,ans;
void dfs(LL len,LL maxn,LL i){
    if(len>maxn) {ans++;ans=ans%INF;}
    for(int j=i-1;j>=1;j--){
        dfs(len+a[j],maxn,j);
    }
    return ;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    LL n;
    cin>>n;
    for(LL i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(LL i=n;i>=1;i--){
        LL maxn=a[i]*2;
        dfs(a[i],maxn,i);
    }
    cout<<ans<<endl;
    return 0;
}
