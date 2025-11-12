#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans=0,flag[5005],ff=0;
void dfs(long long x,long long d,long long y,long long z,long long t){
    if(x==d){
        if(2*y<z)  ans++;
        ans%=998244353;
        if(t==n)  ff=1;
        return;
    }
    for(int i=t;i<=n;i++)
    {
        if(flag[i]==0){
            flag[i]=1;
            dfs(x+1,d,max(y,a[i]),z+a[i],i);
            flag[i]=0;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)  ff=1;
    }
    if(ff==1)  for(int i=3;i<=n;i++)  dfs(0,i,0,0,1);
    else{
        for(int i=3;i<=n;i++){
            long long tt=1,ta=1;
            for(int j=1;j<=i;j++){
                tt*=j;
                tt%=998244353;
            }
            for(int j=n-i+1;j<=n;j++){
                ta*=j;
                ta%=998244353;
            }
            tt=ta/tt;
            ans+=tt;
            ans%=998244353;
        }
    }
    cout<<ans;
    return 0;
}
