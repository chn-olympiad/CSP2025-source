#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[5005];
int f[5005][5005],ans;//how can we figure the formula of f[i] out?
int pw(int x,int mi){
    int res=1;
    while(mi){
        if(mi&1){
            x=(x*x)%mod;
        }res=(res*x)%mod;
        mi=mi>>1;
    }return res;
}
int C(int up,int down){
    int mul=1,chu=1;
    for(int i=0;i<up;i++){
        mul=(1ll*mul*(down-i)%mod)%mod;
        chu=(1ll*(i+1)*chu%mod)%mod;
    }return (mul*pw(chu,mod-2))%mod;
}
int solve(int lst,int edg,int stp,int u,int sum){
    if(stp==edg){
        if(sum>lst)ans=(ans+1)%mod;
        return sum>lst;
    }
    int cnt=0;
    for(int i=u+1;i<lst;i++){
        cnt+=(cnt+solve(lst,edg,stp+1,i,sum+a[i]))%mod;
    }
    return cnt;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i];}
    sort(a+1,a+1+n);
    for(int i=n;i>=3;i--){
        for(int j=i;j>=3;j--){
            solve(i,j-1,0,0,0);
            //???
        }
    }
    cout<<ans;
}

