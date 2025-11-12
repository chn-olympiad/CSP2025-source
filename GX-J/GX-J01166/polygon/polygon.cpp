#include<bits/stdc++.h>
using namespace std;
const int N=1e8+1;
int n,i,j,jf=1,ans,sum,mx,mx2,a[5005],b[N];
void dfs(int k,int u,int v){
    if(k>i){
        if(sum>mx*2){
            jf++;
            ans++;
            return;
        }
        return;
    }
    for(int q=1;q<=v;q++){
        b[jf]+=u;
        sum+=a[u+q];
        mx2=mx;
        mx=max(mx,a[u+q]);
        dfs(k+1,u+q,v-q);
        b[jf]-=u;
        sum-=a[u+q];
        mx=mx2;
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=3;i<=n;i++){
        for(j=0;j<=n-i+1;j++){
            sum=0;mx=0;mx2=0;
            dfs(1,j,n-j);
        }
    }
    for(i=1;i<=jf;i++){
        if(b[i]==b[i-1])ans--;
    }
    cout<<ans%998244353;
    return 0;
}
