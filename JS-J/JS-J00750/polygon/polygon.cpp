
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
int fq(int j){
    ll a=2,r=1;
    while(j){
        if(j%2==1) r=r*a%mod;
        j/=2;
        a=a*a%mod;
    }
    return r;
}
int a[5005],n;
bool cmp(int x,int y){
    return x>y;
}
ll dfs(int dep,int cnt,int mx,int b){
    if(cnt>mx*2&&b>=3) return fq(n-dep+1);
    if(dep==n+1) return 0;
    return (dfs(dep+1,cnt,mx,b)+dfs(dep+1,cnt+a[dep],max(mx,a[dep]),b+1))%mod;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,cmp);
    cout<<dfs(1,0,0,0);
    return 0;
}
