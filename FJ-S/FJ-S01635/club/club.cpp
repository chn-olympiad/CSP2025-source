#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+9;

int n;
int a[N][3];
int d[N];
int c[3];
int ans;
int b[N], bc;

int main(){

    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int T = 0;
    scanf("%d", &T);
    while(T--){
        ans = 0;
        c[0] = c[1] = c[2] = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < 3; j++){
                scanf("%d", &a[i][j]);
            }
        }
        for(int i = 1; i <= n; i++){
            d[i] = 0;
            for(int j = 1; j < 3; j++){
                if(a[i][j] > a[i][d[i]]){
                    d[i] = j;
                }
            }
            c[d[i]]++;
            ans += a[i][d[i]];
        }
        int p = -1;
        if(c[0] > n/2) p = 0;
        if(c[1] > n/2) p = 1;
        if(c[2] > n/2) p = 2;
        if(p == -1){
            printf("%d\n", ans);
            continue;
        }
        bc = 0;
        for(int i = 1; i <= n; i++){
            if(d[i] != p) continue;
            int tp = 0;
            if(p != 0) tp = max(tp, a[i][0]);
            if(p != 1) tp = max(tp, a[i][1]);
            if(p != 2) tp = max(tp, a[i][2]);
            b[++bc] = tp-a[i][d[i]];
        }
        sort(b+1, b+1+bc);
        for(int i = 1; i <= c[p]-n/2; i++){
            ans += b[bc];
            bc--;
        }
        printf("%d\n", ans);
    }

    return 0;
}