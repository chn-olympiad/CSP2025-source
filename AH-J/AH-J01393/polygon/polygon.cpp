#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans,vis[5010];
int cl(int a,int b,int c,int d){
    return a+b+c+d;
}
void dfs(int qs,int zc,int zd,int g){
    if(qs>n||qs+g>n+1){
        return;
    }
    if(zc>zd*2&&g>=3&&vis[cl(qs,zc,zd,g)]==0){
        ans++;
        ans%=998244353;
        vis[cl(qs,zc,zd,g)]=1;
    }
    int q=qs+g;
    zd=max(zd,a[q]);
    int he=zc+a[q];
    dfs(qs,zc+a[q],zd,g+1);
    dfs(qs+1,zc+a[q],zd,g+1);
    dfs(qs+1,zc,zd,g);
    return;
}
int main(){
    freopen("polygon1.in","r",stdin);
    freopen("polygon1.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        dfs(i,0,0,0);
    }
    cout<<ans;
    return 0;
}
