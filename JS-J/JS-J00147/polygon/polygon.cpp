#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n;
int a[5050],dp[5050][5050];
ll cnt=0;
int f=1;
void dfs(int x,int c,int s,int m){
    if(c>=3 and s>2*m){
        cnt++;
        cnt%=mod;
    }
    for(int i=x+1;i<=n;i++){
        dfs(i,c+1,s+a[i],max(m,a[i]));
    }
    return;
}
int C(int x){
    int sum=1;
    int q=1;
    for(int k=n,kk=1;k>(n-x),kk<=x;k--,kk++){
        sum*=k;
        sum/=kk;
        sum%=mod;
    }
    return sum;
}
void solve2(){
    for(int i=3;i<=n;i++){
        cnt+=C(i);
        cnt%=mod;
    }
    cout<<cnt;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) f=0;
    }
    if(f){
        solve2();
        return 0;
    }
    sort(a+1,a+n+1);
    // ll s,m;
    // for(int i=3;i<=n;i++){
    //     s=0,m=0;
    //     for(int j=1;j<=i;j++){
    //         s+=j;
    //         m=max(m,a[j]);
    //     }
    //     if(s>2*m){
    //         dp[i][i]=1;
    //         ll la=a[i];
    //     }
    // }
    // for(int i=3;i<=n;i++){
    //     cnt+=dp[n][i];
    //     cnt%=mod;
    // }
    dfs(0,0,0,0);
    cout<<cnt;
    return 0;
}
//364pts
//T4 broke my AK dream