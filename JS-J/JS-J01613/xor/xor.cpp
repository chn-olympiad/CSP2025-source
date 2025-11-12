#include<iostream>
#include<stdio.h>
#include<unordered_map>

using namespace std;

int n, l, a[500100], s[500100], mx, dp[500100], k, pre_max[500100];
unordered_map<int, int> past;

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for(int i = 1;i <= n;i++){
        scanf("%d", a+i);
        s[i] = s[i-1] ^ a[i];
    }
    past[0] = 0;
    for(int i = 1;i <= n;i++){
        if(past.find(s[i] ^ k) != past.end()){
            dp[i] = dp[pre_max[(*past.find(s[i] ^ k)).second]]+1;
        }
        past[s[i]] = i;
        if(dp[i] >= dp[pre_max[i-1]]) pre_max[i] = i;
        else pre_max[i] = pre_max[i-1];
    }
    for(int i = 1;i <= n;i++)
        mx = max(dp[i], mx);
    printf("%d", mx);
}
