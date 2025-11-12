#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n;
int a[5005];
int sum,maxv,cnt;
int ans;
void dfs(int dep){
    if(dep>n){
        if(sum>maxv*2&&cnt>=3){
            ans=(ans+1)%mod;
        }
        return ;
    }
    dfs(dep+1);
    int t=maxv;
    cnt++;sum+=a[dep];maxv=max(maxv,a[dep]);
    dfs(dep+1);
    cnt--;sum-=a[dep];maxv=t;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n==3){
        if(a[1]+a[2]>a[3]){
            cout<<1;
        }
        else{
            cout<<0;
        }
        return 0;
    }
    if(n<=20){
        dfs(1);
        cout<<ans;
        return 0;
    }
    return 0;
}
