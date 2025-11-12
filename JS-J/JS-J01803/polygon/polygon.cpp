#include<bits/stdc++.h>
#include<bits/stl_algo.h>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N=5e3+5;
int n,a[N],dp[N][N],ans;
void dfs(int i,int j,int mx,int sum){
    if (i==n){
        ans++;
        return;
    }
    for (int k=j+1;k<=n;k++){
        if (i<=2||sum+a[k]>2*max(mx,a[k])){
            if (i>=3)ans++;
            dfs(i+1,k,max(mx,a[k]),sum+a[k]);
        }
    }
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)cin>>a[i];
    dfs(0,0,0,0);
    cout<<ans<<endl;
    return 0;
}
