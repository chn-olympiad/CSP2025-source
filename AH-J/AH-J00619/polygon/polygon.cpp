#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
bool f=1;
long long ans=0;
void dfs(int i,int sum,int mx,int cnt){
    if(i==n+1){
        if(sum>mx*2&&cnt>=3) ans=(ans+1)%998244353;
        return;
    }
    dfs(i+1,sum+a[i],max(mx,a[i]),cnt+1);
    dfs(i+1,sum,mx,cnt);
}
long long c(int m,int i){
    i=min(i,m-i);
    long long ans=1;
    for(int j=0;j<i;j++) ans*=(m-j);
    for(int j=1;j<=i;j++) ans/=j;
    return ans;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]!=1) f=0;
    }
    if(f==1){
        long long ans=0;
        for(int i=3;i<=n;i++){
            ans+=c(n,i);
        }
        cout<<(ans%998244353);
        return 0;
    }
    if(n<=50){
        dfs(1,0,0,0);
        cout<<ans;
        return 0;
    }
    cout<<0;
    return 0;
}
