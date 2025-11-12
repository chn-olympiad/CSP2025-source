#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5005],mx;
const int MOD=998244353;
int f(int n){
    int sum=1;
    for(int i=1;i<=n;i++){
        sum=(sum*2)%MOD;
    }
    sum=(sum+MOD-1-n-(n*n-n)/2)%MOD;
    return sum;
}
int dfs(int id,int sum,int maxa){
    if(id==n+1){
        if(sum>maxa*2){
            return 1;
        }
        return 0;
    }
    int t=dfs(id+1,sum+a[id],max(maxa,a[id]))%MOD;
    t+=dfs(id+1,sum,maxa)%MOD;
    return t%MOD;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    if(n<=3){//1~3
        if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2){
            cout<<1;
        }else{
            cout<<0;
        }
    }else if(n<=20){//4~10
        cout<<dfs(1,0,0);
    }else if(mx<=1){//15~20
        int ans=f(n)%MOD;
        ans%=MOD;
        cout<<ans;
    }
    return 0;
}
