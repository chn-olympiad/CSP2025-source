#include<bits/stdc++.h>
#include<bits/stl_algo.h>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N=2e3+5;
int n,k,a[N],ans;
int dp[N][N];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        dp[i][i]=a[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++)dp[i][j]=dp[i][j-1]^a[j];
    }
    for (int i=1;i<=n;i++){
        int tmp=0;
        for (int j=i;j<=n;j++){
            if (dp[i][j]==k){
                tmp=j;
                break;
            }
        }
        if (tmp!=0)ans++;
        i=tmp;
    }
    cout<<ans<<endl;
    return 0;
}
