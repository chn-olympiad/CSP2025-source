#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int T;
int n,a[100007][2] = {0},b[100007][2] = {0};
void p(int x1,int x2,int x3,int i){
    if(x1 > x2 && x1 > x3){
        if(x2 > x3){ a[i][0] = x1; b[i][0] = 1; a[i][1] = x2; b[i][1] = 2; }
        else       { a[i][0] = x1; b[i][0] = 1; a[i][1] = x3; b[i][1] = 3; }
    }
    else if(x2 > x1 && x2 > x3){
        if(x1 > x3){ a[i][0] = x2; b[i][0] = 2; a[i][1] = x1; b[i][1] = 1; }
        else       { a[i][0] = x2; b[i][0] = 2; a[i][1] = x3; b[i][1] = 3; }
    }
    else{
        if(x1 > x2){ a[i][0] = x3; b[i][0] = 3; a[i][1] = x1; b[i][1] = 1; }
        else       { a[i][0] = x3; b[i][0] = 3; a[i][1] = x2; b[i][1] = 2; }
    }
    return ;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> T;
    for(int xx = 0;xx < T;xx++){
        cin >> n;
        int x1,x2,x3;
        for(int i = 0;i < n;i++){
            cin >> x1 >> x2 >> x3;
            p(x1,x2,x3,i);
        }
        int c[4] = {0,0,0,0};
        for(int i = 0;i < n;i++){
            c[b[i][0]]++;
        }
        if(c[1] <= n/2 && c[2] <= n/2 && c[3] <= n/2){
            int ans = 0;
            for(int i = 0;i < n;i++){
                ans+=a[i][0];
            }
            cout << ans << endl;
            continue;
        }
        else{
            int ans = 0;
            for(int i = 0;i < n;i++){
                for(int k = i;k < n-1;k++){
                    if(a[i][0] > a[i+1][0]){
                        a[i][0]+=a[i+1][0];
                        a[i+1][0]=a[i][0]-a[i+1][0];
                        a[i][0]=a[i][0]-a[i+1][0];
                    }
                }
            }
            for(int i = 0;i < n/2;i++){
                ans += a[i][0];
            }
            cout << ans << endl;
        }
    }
    return 0;
}
