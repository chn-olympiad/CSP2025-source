#include<bits/stdc++.h>

using namespace std;

const int N = 5e3 + 10, P = 998244353;

int n, a[N], maxw, nowi, ans;
int maxa;
int c[N][N];

void dfs(int x, int sum, int cnt){
    if(x == nowi){
        if((cnt >= 2) && (sum > maxw)){
            ans = (ans + 1) % P;
        }
        return;
    }
    dfs(x + 1, sum + a[x], cnt + 1);
    dfs(x + 1, sum, cnt);
}

int main(){

    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    scanf("%d", &n);
    for(int i  =1; i <= n; i ++){
        scanf("%d", &a[i]);
        maxa = max(maxa, a[i]);
    }

    //tui
    c[0][0] = 1;
    for(int i = 1; i <= n; i ++){
        c[i][0] = 1;
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= i; j ++){
            c[i][j] = (1ll * c[i - 1][j - 1] + 1ll * c[i - 1][j]) % P;
            // cout << c[i][j] << " ";
        }
        // cout << endl;
    }
    if(maxa == 1){
        //15 ~ 20
        //C(n, 3)
        printf("%d\n", c[n][3]);
        return 0;
    }

    
    //1~10
    sort(a + 1, a + n + 1);
    if(n == 3){
        if(a[1] + a[2] + a[3] > 2 * a[3]){
            printf("1\n");
        }else{
            printf("0\n");
        }
        return 0;
    }
    for(nowi = 3; nowi <= n; nowi ++){
        //this is maxw;
        //choose at leat 2 before
        maxw = a[nowi];
        dfs(1, 0, 0);
    }
    printf("%d\n", ans);


    return 0;
}