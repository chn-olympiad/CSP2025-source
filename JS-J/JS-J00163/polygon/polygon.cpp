#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int maxn = 5000 + 10;
int n,a[maxn],ans;
void dfs(int id,int s,int m,int cnt){
    if(id>n){
        if(s>m*2&&cnt>=3){
            ans++;
            return;
        }
        return;
    }
    for(int i = id;i <= n;i++){
        dfs(i+1,s+a[i],max(a[i],m),cnt+1);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    dfs(1,0,0,0);
    cout<<ans;
    return 0;
}
