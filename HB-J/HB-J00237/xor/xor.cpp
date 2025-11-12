#include <bits/stdc++.h>
using namespace std;

//Hey, guys! This program can only suit n <= 1e+4.
//So I can only get 60 points !!!

int n, k, tmp;
int a[500008];
long long maxn, cnt;

long long lmax(long long p, long long q){
    return p > q ? p : q;
}

int main(){
    #if 1
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    #endif
    scanf(" %d %d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf(" %d", &a[i]);
    }
    maxn = -1;
    for(int i = 1; i <= n; i++){
        tmp = a[i];
        cnt = 0;
        for(int j = i + 1; j <= n; j++){
            if(tmp == k){
                cnt++;
                tmp = a[j];
            }
            else{
                tmp = tmp xor a[j];
            }
        }
        if(tmp == k){
            cnt++;
        }
        maxn = lmax(cnt, maxn);
    }
    printf("%lld\n", maxn);
    return 0;
}