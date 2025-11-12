#include<bits/stdc++.h>
using namespace std;
int n,a[100005],s[100005],ans;
const int mod=998244353;
void dfs(int x,int sum,int lst){
    if(sum<0&&lst==1) ans=(ans+1)%mod;
    if(x==0) return;
    if(sum>=s[x]) return;
    dfs(x-1,sum-a[x],1);
    dfs(x-1,sum,0);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    s[1]=a[1];
    for(int i=2;i<=n;i++) s[i]=s[i-1]+a[i];
    if(n<=20){
        for(int i=n;i>=3;i--) dfs(i-1,a[i],0);
        cout<<ans;
    }else{
        int sum=1;
        for(int i=1;i<=n;i++) sum=(sum*2)%mod;
        sum-=(1+n+(n-1)*n/2);
        cout<<sum;
    }
    return 0;
}
