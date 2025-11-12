#include<bits/stdc++.h>
using namespace std;
int a[100010][5] = {0};
//dp

struct node{
    int cnta, cntb, cntc, ans;
} f[100010][5];

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        int n, mpe;
        scanf("%d", &n);
        mpe = n / 2;
        for (int i = 1; i <= n; i++){
            scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
            f[i][1].cnta = f[i][1].cntb = f[i][1].cntc = f[i][1].ans = 0;
            f[i][2].cnta = f[i][2].cntb = f[i][2].cntc = f[i][2].ans = 0;
            f[i][3].cnta = f[i][3].cntb = f[i][3].cntc = f[i][3].ans = 0;
        }
        f[1][1].ans = a[1][1];
        f[1][1].cnta = 1;
        f[1][2].ans = a[1][2];
        f[1][2].cntb = 1;
        f[1][3].ans = a[1][3];
        f[1][3].cntc = 1;
        for (int i = 2; i <= n; i++){
            //f[i][1]
            if (f[i - 1][1].cnta >= mpe){
                if (f[i - 1][2].ans > f[i - 1][3].ans){
                    f[i][1].ans = f[i - 1][2].ans + a[i][1];
                    f[i][1].cnta = f[i - 1][1].cnta;
                    f[i][1].cntb = f[i - 1][1].cntb + 1;
                    f[i][1].cntc = f[i - 1][1].cntc;
                }
                else{
                    f[i][1].ans = f[i - 1][3].ans + a[i][1];
                    f[i][1].cnta = f[i - 1][1].cnta;
                    f[i][1].cntb = f[i - 1][1].cntb;
                    f[i][1].cntc = f[i - 1][1].cntc + 1;
                }
            }
            else{
                if ((f[i - 1][1].ans > f[i - 1][2].ans) && (f[i - 1][1].ans > f[i - 1][3].ans)){
                    f[i][1].ans = f[i - 1][1].ans + a[i][1];
                    f[i][1].cnta = f[i - 1][1].cnta + 1;
                    f[i][1].cntb = f[i - 1][1].cntb;
                    f[i][1].cntc = f[i - 1][1].cntc;
                }
                else if ((f[i - 1][2].ans > f[i - 1][1].ans) && (f[i - 1][2].ans > f[i - 1][3].ans)){
                    f[i][1].ans = f[i - 1][2].ans + a[i][1];
                    f[i][1].cnta = f[i - 1][1].cnta;
                    f[i][1].cntb = f[i - 1][1].cntb + 1;
                    f[i][1].cntc = f[i - 1][1].cntc;
                }
                else{
                    f[i][1].ans = f[i - 1][3].ans + a[i][1];
                    f[i][1].cnta = f[i - 1][1].cnta;
                    f[i][1].cntb = f[i - 1][1].cntb;
                    f[i][1].cntc = f[i - 1][1].cntc + 1;
                }
            }
            //f[i][2]
            if (f[i - 1][2].cntb >= mpe){
                if (f[i - 1][1].ans > f[i - 1][3].ans){
                    f[i][2].ans = f[i - 1][1].ans + a[i][2];
                    f[i][2].cnta = f[i - 1][2].cnta + 1;
                    f[i][2].cntb = f[i - 1][2].cntb;
                    f[i][2].cntc = f[i - 1][2].cntc;
                }
                else{
                    f[i][2].ans = f[i - 1][3].ans + a[i][2];
                    f[i][2].cnta = f[i - 1][2].cnta;
                    f[i][2].cntb = f[i - 1][2].cntb;
                    f[i][2].cntc = f[i - 1][2].cntc + 1;
                }
            }
            else{
                if ((f[i - 1][1].ans > f[i - 1][2].ans) && (f[i - 1][1].ans > f[i - 1][3].ans)){
                    f[i][2].ans = f[i - 1][1].ans + a[i][2];
                    f[i][2].cnta = f[i - 1][2].cnta + 1;
                    f[i][2].cntb = f[i - 1][2].cntb;
                    f[i][2].cntc = f[i - 1][2].cntc;
                }
                else if ((f[i - 1][2].ans > f[i - 1][1].ans) && (f[i - 1][2].ans > f[i - 1][3].ans)){
                    f[i][2].ans = f[i - 1][2].ans + a[i][2];
                    f[i][2].cnta = f[i - 1][2].cnta;
                    f[i][2].cntb = f[i - 1][2].cntb + 1;
                    f[i][2].cntc = f[i - 1][2].cntc;
                }
                else{
                    f[i][2].ans = f[i - 1][3].ans + a[i][2];
                    f[i][2].cnta = f[i - 1][2].cnta;
                    f[i][2].cntb = f[i - 1][2].cntb;
                    f[i][2].cntc = f[i - 1][2].cntc + 1;
                }
            }
            //f[i][3]
            if (f[i - 1][3].cntc >= mpe){
                if (f[i - 1][2].ans > f[i - 1][1].ans){
                    f[i][3].ans = f[i - 1][2].ans + a[i][3];
                    f[i][3].cnta = f[i - 1][3].cnta;
                    f[i][3].cntb = f[i - 1][3].cntb + 1;
                    f[i][3].cntc = f[i - 1][3].cntc;
                }
                else{
                    f[i][3].ans = f[i - 1][1].ans + a[i][3];
                    f[i][3].cnta = f[i - 1][3].cnta;
                    f[i][3].cntb = f[i - 1][3].cntb;
                    f[i][3].cntc = f[i - 1][3].cntc;
                }
            }
            else{
                if ((f[i - 1][1].ans > f[i - 1][2].ans) && (f[i - 1][1].ans > f[i - 1][3].ans)){
                    f[i][3].ans = f[i - 1][1].ans + a[i][3];
                    f[i][3].cnta = f[i - 1][3].cnta + 1;
                    f[i][3].cntb = f[i - 1][3].cntb;
                    f[i][3].cntc = f[i - 1][3].cntc;
                }
                else if ((f[i - 1][2].ans > f[i - 1][1].ans) && (f[i - 1][2].ans > f[i - 1][3].ans)){
                    f[i][3].ans = f[i - 1][2].ans + a[i][3];
                    f[i][3].cnta = f[i - 1][3].cnta;
                    f[i][3].cntb = f[i - 1][3].cntb + 1;
                    f[i][3].cntc = f[i - 1][3].cntc;
                }
                else{
                    f[i][3].ans = f[i - 1][3].ans + a[i][3];
                    f[i][3].cnta = f[i - 1][3].cnta;
                    f[i][3].cntb = f[i - 1][3].cntb;
                    f[i][3].cntc = f[i - 1][3].cntc + 1;
                }
            }
        }
        printf("%d\n", max(f[n][1].ans, max(f[n][2].ans, f[n][3].ans)));
    }

    return 0;
}