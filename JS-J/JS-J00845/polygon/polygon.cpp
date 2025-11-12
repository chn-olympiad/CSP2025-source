#include <bits/stdc++.h>
using namespace std;

const int Mod = 998244353;
int a[5005];
int n;
long long ans=0;

void dfs(int len,int i,int last,int x,int maxn){
    if(i == len){
        if(x > 2*maxn){
            ans = (ans+1)%Mod;
        }
        return;
    }
    if(last > n){
        return;
    }
    for(int k = last;k+len-i-1 <= n;k++){
        if(len - i == 1 && a[k] > x){
            break;
        }
        dfs(len,i+1,k+1,x+a[k],a[k]);
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    for(int len = 3;len <= n;len++){
        dfs(len,0,1,0,-1);
    }
    cout << ans;
    return 0;
}
