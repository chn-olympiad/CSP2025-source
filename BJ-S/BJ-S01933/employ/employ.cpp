#include<bits/stdc++.h>
using namespace std;
int n,m,ti[1000],c[1000],ans,a[1000],jc[1000];
void dfs(int dp,int fq,int xx,int res){
    a[xx]=1;
    int f=0;
    if(ti[dp]==1&&fq<c[xx]){
        res+=1;f=1;
    }
    if(res>=m){
        ans=(ans+jc[n-dp])%998244353;
        a[xx]=0;
        return;
    }
    if(m-res>n-dp){
        a[xx]=0;return;
    }
    if(dp==n){
        a[xx]=0;return;
    }
    for(int i=1;i<=n;i++){
        if(a[i])continue;
        if(f==0)dfs(dp+1,fq+1,i,res);
        else dfs(dp+1,fq,i,res);
    }
    a[xx]=0;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;jc[0]=1;
    for(int i=1;i<=n;i++)jc[i]=jc[i-1]*i%998244353;
    for(int i=1;i<=n;i++){
        char p;
        cin>>p;
        if(p=='0')ti[i]=0;
        if(p=='1')ti[i]=1;
    }
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=n;i++)dfs(1,0,i,0);
    cout<<ans<<endl;
    return 0;
}
