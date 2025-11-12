#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int ans;
void dfs(int k,int summ,int maxn){
    if(k>n){
        if(summ>2*maxn){
            ans++;
        }
        return ;
    }
    dfs(k+1,summ,maxn);
    dfs(k+1,summ+a[k],max(maxn,a[k]));
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0,0);
    cout<<ans;
    return 0;
}
