#include<bits/stdc++.h>
using namespace std;
long long a[5005];
long long ans=0,n;
long long vis[5005][50000];
long long h=998244353;
long long dfs(long long x,long long l){
    if(vis[x][l]!=0){
        return vis[x][l];
    }
    if(x==n+1){
        return 0;
    }
    long long u=0;
    if(a[x]<l){
        u++;
    }
    long long l1=dfs(x+1,l+a[x]),l2=dfs(x+1,l);
    vis[x][l]=l1+l2+u;
    vis[x][l]%=h;
    return vis[x][l];
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long u=dfs(1,0);
    cout<<u;
    return 0;
}
