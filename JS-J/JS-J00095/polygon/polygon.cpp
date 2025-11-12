#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int cnt;
void dfs(int zd,int sum,int k,int jsq){
    if(sum>zd*2&&jsq>=3){
        cnt++;
    }
    for(int i=k+1;i<=n;i++){
        dfs(max(zd,a[i]),sum+a[i],i,jsq+1);
    }
}
int c(int n,int m){
    int x=1,y=1;
    for(int i=1;i<=m;i++){
        x*=i;y*=n-i+1;
    }
    return y/x;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=25){
        cnt=0;
        dfs(-1,0,0,0);
        cout<<cnt;
    }else{
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=c(n,i);
        }
        cout<<ans;
    }
    return 0;
}
