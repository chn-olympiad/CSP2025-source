#include<bits/stdc++.h>

using namespace std;

int n, k;
int a[500010];
int s[500010];
struct Node{
    int x, y;
    bool operator < (const Node &A){
        return y < A.y || (y == A.y && x < A.x);
    }
}f[500010];
int ans, cnt;
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++)
        s[i] = s[i - 1] ^ a[i];
    for(int i = 0; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            if((s[j] ^ s[i]) == k){
                f[++cnt].x = i + 1, f[cnt].y = j;
                //printf("i:%d j:%d si:%d sj:%d %d\n", i, j, s[i], s[j], s[j] ^ s[i]);
            }
    if(cnt == 0){
        printf("0\n");
        return 0;
    }
    ans = 1;
    sort(f + 1, f + cnt + 1);
    int t = 1;
    for(int i = 2; i <= cnt; i++)
        if(f[i].x > f[t].y)
            ans++, t = i;
    printf("%d\n", ans);
    return 0;
}
