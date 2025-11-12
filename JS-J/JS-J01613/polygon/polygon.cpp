#include<iostream>
#include<stdio.h>

using namespace std;

int n, t[5010], l[5010], comd[5010][5010];

int dfs(int p, int m){
    int s = 0;
    if(p == m+1){
        int mx = t[l[1]];
        s = t[l[1]];
        for(int i = 2;i <= m;i++){
            s += t[l[i]];
            mx = max(t[l[i]], mx);
        }
        return s > 2*mx;
    }
    for(int i = l[p-1]+1;i <= n;i++){
        l[p] = i;
        s = (s+dfs(p+1, m)) % 998244353;
    }
    return s;
}

int C(int i, int j){
    if(j == 1 || j == i) return 1;
    if(comd[i][j]) return comd[i][j];
    return comd[i][j] = (C(i-1, j) + C(i-1, j-1)) % 998244353;
}

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1;i <= n;i++){
        scanf("%d", t+i);
    }
    if(n <= 20){
        l[0] = 0;
        int s = 0;
        for(int i = 3;i <= n;i++){
            s += dfs(1, i);
            s %= 998244353;
        }
        printf("%d", s);
    }
    else{
        int s = 0;
        for(int i = 3;i <= n;i++){
            s += C(n, i);
            s %= 998244353;
        }
        printf("%d", s);
    }
}
