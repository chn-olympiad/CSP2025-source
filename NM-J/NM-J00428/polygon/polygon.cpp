#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a[5005], sum, mmax, ans, old;
void dfs(int b, int i, int u){
    if(u == i){
        if(sum > mmax * 2){
            ans++;
            return ;
        }
        return ;
    }else{
        for(int j = b;j <= n - i + u;++j){
            if(mmax < a[j]){
                old = mmax;
                mmax = a[j];
            }
            sum += a[j];
            dfs(j + 1, i, u + 1);
            sum -= a[j];
            mmax = old;
        }
    }
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin  >>  n;
    for(int i = 0;i < n;++i){
        cin  >>  a[i];
    }
    for(int i = 3;i <= n;++i){
        sum = 0;
        mmax = 0;
        dfs(0, i, 0);
    }
    cout  <<  ans;
    return 0;
}
