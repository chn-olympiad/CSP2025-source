#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t, n;
long long sum;
int j[3];
int a[N][3];
int ans[N];
int bk[N][3];
long long op;
void dfs(int x){
    if(x > n){
        for(int i = 1; i<= n; i++) sum += ans[i];
        op = max(sum, op);
        sum = 0;
        return ;
    }
    for(int i = 1; i <= 3; i++){
        if(!bk[x][i] && j[i] < n / 2){
            ans[x] = a[x][i];
            bk[x][i] = 1;
            j[i] ++;
            dfs(x + 1);
            bk[x][i] = 0;
            j[i] --;
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++){
            scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
        }
        dfs(1);
        printf("%lld\n", op);
        op = 0;
    }
}
