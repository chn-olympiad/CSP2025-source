#include<bits/stdc++.h>
using namespace std;
int n,a[5010],p[5010],vis[5010],cnt;
void dfs(int k,int mx,int s,int m,int l){
    if(k==m+1){
        if(s>2*mx){
            cnt++;
        }
        return ;
    }
    for(int i=l;i<=n;i++){
        p[k]=a[i];
        dfs(k+1,max(mx,a[i]),s+a[i],m,i+1);

    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=3;i<=n;i++){
        dfs(1,0,0,i,1);
    }
    cout<<cnt;
    return 0;
}
