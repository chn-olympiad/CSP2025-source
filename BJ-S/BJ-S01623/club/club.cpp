#include<bits/stdc++.h>
const int N = 1e5+10;

using namespace std;

int num[4];
int a[N][4];
int T, n, ans;
void work(int cur, int res){
    if(cur == n+1){
        ans = max(ans, res);
        return ;
    }
    for(int i=1;i<=3;i++){
        if(num[i] < n/2){
            num[i] ++;
            work(cur+1, res+a[cur][i]);
            num[i] --;
        }
    }
}

int main(){

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        ans = 0;
        num[1] = num[2] = num[3] = 0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                scanf("%d", &a[i][j]);
            }
        }
        work(1, 0);
        printf("%d\n", ans);
    }

    return 0;
}
