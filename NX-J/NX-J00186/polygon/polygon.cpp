#include <bits/stdc++.h>
using namespace std;
int a[5010];
int n;
int ans;
void dfs(int now,int sum,int chosen,int maxx){
    if(now >= n){
        if((chosen >= 3)&&(sum > maxx*2)){
            ans++;
            ans %= 998244353;
        }
        return;
    }
    dfs(now+1,sum+a[now],chosen + 1,max(maxx,a[now]));
    dfs(now+1,sum,chosen,maxx);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    dfs(0,0,0,0);
    cout<<ans;
    return 0;
}
