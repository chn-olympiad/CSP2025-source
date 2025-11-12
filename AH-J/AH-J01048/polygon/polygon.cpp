#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5005;
LL a[N],ans,n;
void dfs(LL cur,LL sum,LL maxn,LL cnt){
    if(cur>n){
        if(sum>2*maxn&&cnt>=3) ans++;
        ans%=998244353;
        return ;
    }
    dfs(cur+1,sum+a[cur],max(maxn,a[cur]),cnt+1);
    dfs(cur+1,sum,maxn,cnt);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    LL maxa=0;
    cin>>n;
    for(LL i=1;i<=n;i++){
        cin>>a[i];
        maxa=max(maxa,a[i]);
    }
    if(maxa==1){
        for(LL i=3;i<=n;i++){
            LL cum=1;
            for(LL j=0;j<i;j++){
                cum*=(n-j);
                cum/=(j+1);
                cum%=998244353;
            }
            ans+=cum;
            ans%=998244353;
        }
        cout<<ans%998244353;
        return 0;
    }
    dfs(1,0,0,0);
    cout<<ans%998244353;
    return 0;
}
