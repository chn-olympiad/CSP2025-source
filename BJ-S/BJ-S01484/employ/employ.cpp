#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int q = 998244353;
int n,k,a[507];
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> k;
    cin >> s;
    int xx = 1,yy;
    for(int i = 0;i < n;i++){
        if(s[i] == '0'){
            xx = 0;
        }
        cin >> a[i];
        if(a[i] == 0){
            yy++;
        }
    }
    if(xx){
        int ans = 1;
        for(int i = 1;i <= yy;i++){
            ans*=i;
        }
        for(int i = 0;i < n;i++){
            if(a[i] == 0)
            ans*=(a[i]+i);
        }
        cout<<ans;
    }
    return 0;
}