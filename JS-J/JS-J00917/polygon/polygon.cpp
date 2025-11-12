#include<bits/stdc++.h>
using namespace std;
int ans,n,b[5005],in[5005];
bool check(int a[],int m){
    int maxx=0,cnt=0;
    for(int i=1;i<=m;i++)
        cnt+=a[i],maxx=max(a[i],maxx);
    if(cnt<=2*maxx) return 0;
    return 1;
}
void dfs(int dep,int t){
    if(dep>n){
        if(t>2) ans+=check(b,t);
        memset(b,sizeof(b),0);
        return;
    }
    dfs(dep+1,t);
    b[++t]=in[dep];
    dfs(dep+1,t+1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>in[i];
    dfs(1,0);
    cout<<(ans%998244353);
    return 0;
}