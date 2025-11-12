#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
void dfs(int u,int cnt,int z,int xs,int x){
    if(cnt>z*2&&xs>=3&&x){
        ans++;
    }
    if(u==n+1)return;
    dfs(u+1,cnt+a[u],a[u],xs+1,1);
    dfs(u+1,cnt,z,xs,0);
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    if(n<=20)dfs(1,0,0,0,0);
    else{
        for(int i=3;i<=n;i++){
            int x=0
            ans+=c()
        }
    }
    cout<<ans;
    return 0;
}
