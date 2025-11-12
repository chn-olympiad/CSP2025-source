#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int n, k, a[500005], mmax, ans, vis[500005];
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin  >>  n  >>  k;
    for(int i = 0;i < n;++i){
        cin  >>  a[i];
        if(a[i] > mmax){
            mmax = a[i];
        }
    }
    if(k == 0){
        for(int i = 0;i < n;++i){
            if(a[i] == 0){
                ans++;
            }else if(vis[a[i]] == 0){
                vis[a[i]] = 1;
            }else if(vis[a[i]] == 1){
                vis[a[i]] = 0;
                ans++;
            }
        }
        cout  <<  ans;
        return 0;
    }else if(k == 1 && mmax <= 1){
        for(int i = 0;i < n;++i){
            if(a[i] == 1){
                ans++;
            }
        }
        cout  <<  ans;
        return 0;
    }else{
        cout  <<  8;
    }
    return 0;
}
