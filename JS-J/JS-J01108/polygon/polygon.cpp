#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans;
void dfs(int now,int all,int mx,int num){
    if(now>n){
        return ;
    }if(all>mx*2&&num>=3){
        ans++;
        ans%=998244353;
    }
    dfs(now+1,all+a[now+1],max(mx,a[now+1]),num+1);
    dfs(now+1,all,mx,num);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(0,0,0,0);
    ans%=998244353;
    cout<<ans-2;
    return 0;
}
