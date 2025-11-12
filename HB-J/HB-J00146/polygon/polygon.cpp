#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010],ans;
void dfs(int x,int sum,int ma){
    if(x == n+1){
        if(sum>ma*2){
            ans++;
        }
        return;
    }
    if(x!=n+1){
        dfs(x+1,sum,ma);
        dfs(x+1,sum+a[x],max(ma,a[x]));
    }
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    dfs(1,0,0);
    cout << ans;
    return 0;
}
