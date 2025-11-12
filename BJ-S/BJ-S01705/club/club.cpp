#include<bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
using LL = long long;
const int NR = 1e5;
namespace SubAll{
    struct Node{
        PII x[4];
        PII del;
        int Max;
    }a[NR + 10];
    bool cmp(Node x, Node y){
        if(x.del != y.del) return x.del > y.del;
        return x.Max > y.Max;
    }
    void solve(int n){
        for(int i = 1;i <= n;i++){
            scanf("%d%d%d", &a[i].x[1].first, &a[i].x[2].first, &a[i].x[3].first);
            a[i].x[1].second = 1;
            a[i].x[2].second = 2;
            a[i].x[3].second = 3;
            sort(a[i].x + 1, a[i].x + 4);
            a[i].Max = a[i].x[3].first;
            a[i].del = {a[i].x[3].first - a[i].x[2].first, a[i].x[2].first - a[i].x[1].first};
        }
        // for(int i = 1;i <= n;i++){
        //     printf("a[%d]={{%d, %d, %d}, Max=%d, del={%d, %d}}\n", i, a[i].x[1].first, a[i].x[2].first, a[i].x[3].first, a[i].Max, a[i].del.first, a[i].del.second);
        // }
        sort(a + 1, a + 1 + n, cmp);
        int cnt[4] = {0, 0, 0, 0};
        LL sum = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 3;j >= 1;j--){
                int index = a[i].x[j].second;
                if(cnt[index] < (n >> 1)){
                    cnt[index]++;
                    sum += a[i].x[j].first;
                    break;
                }
            }
        }
        printf("%lld\n", sum);
    }
}
namespace Sub11{
    const int MR = 2e2;
    const int KR = 1e2;
    int a[MR + 10][4];
    int dp[MR + 10][KR + 10][KR + 10];
    void solve(int n){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= 3;j++){
                scanf("%d", &a[i][j]);
            }
        }
        for(int i = 0;i <= n + 1;i++){
            for(int j = 0;(j << 1) <= n + 2;j++){
                for(int k = 0;(k << 1) <= n + 2;k++){
                    dp[i][j][k] = 0;
                }
            }
        }
        int Max = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 0;j <= i && (j << 1) <= n;j++){
                for(int k = 0;j + k <= i && (k << 1) <= n;k++){
                    int l = (i - j - k);
                    if((l << 1) > n) continue;
                    if(j){
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + a[i][1]);
                    }
                    if(k){
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + a[i][2]);
                    }
                    if(l){
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + a[i][3]);
                    }
                    if(i == n){
                        Max = max(Max, dp[i][j][k]);
                    }
                }
            }
        }
        printf("%d\n", Max);
    }
}

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        if(n <= 200){
            Sub11::solve(n);
        }
        else{
            SubAll::solve(n);
        }
    }
    return 0;
}
/*
cd ~/club && g++ club.cpp -o club && ./club
*/