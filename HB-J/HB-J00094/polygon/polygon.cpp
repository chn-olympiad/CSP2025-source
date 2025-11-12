#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
typedef long long ll;
ll n,a[5005];
bool flag = 1;
void solve1(){
    if(n==2||n==1||n==0){
        cout<<0;
        exit(0);
    }
    ll sum = 0,maxn = 0;
    for(ll i = 1;i<=n;i++){
        sum+=a[i];
        maxn = max(maxn,a[i]);
    }
    if(sum>2*maxn){
        cout<<1;
    }
    else cout<<0;
    exit(0);
}
void solve2(){
    ll sum,last;
    sum = n*(n-1)*(n-2)/6;
    last = sum;
    for(ll i = 4;i<=n;i++){
        ll temp = last*(n-i+1)/i;
        sum=sum+temp;
        sum%=MOD;
        last = temp;
        last%=MOD;
    }
    cout<<sum%MOD;
    exit(0);
}
ll s[50005],vis[50005],ans;
void dfs(ll step,ll sum,ll maxn){
    if(step>n){
        if(sum>2*maxn) ans++;
        ans%=MOD;
        return ;
    }
    if(vis[step]) return ;
    vis[step] = 1;
    dfs(step+1,sum+a[step],max(maxn,a[step]));
    vis[step] = 0;
    dfs(step+1,sum,maxn);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(ll i = 1;i<=n;i++){
        cin>>a[i];
        if(i>=2&&a[i]!=a[i-1]) flag = 0;
        s[i] = s[i-1]+a[i];
    }
    if(n<=3){
        solve1();
    }
    else if(flag){
        solve2();
    }
    else{
        dfs(1,0,0);
        cout<<ans;
    }
    return 0;
}
