#include<bits/stdc++.h>
using namespace std;
int a[105], seat[105][105];
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m, score, i, j;
    scanf("%d%d", &n, &m);
    for(i = 1;i <= n * m;i++){
        scanf("%d", &a[i]);
        if(i == 1) score = a[i];
    }
    sort(a + 1, a + n * m + 1, greater<int>());
    int cnt = 0;i = 1, j = 1;
    while(i * j <= n * m){
        seat[i][j] = a[++cnt];
        if(j % 2) i == n ? j++ : i++;
        else i == 1 ? j++ : i--;
    }
    for(i = 1;i <= n;i++)
        for(j = 1;j <= m;j++)
            if(seat[i][j] == score){
                printf("%d %d\n", j, i);
                return 0;
            }
    return 0;
}
