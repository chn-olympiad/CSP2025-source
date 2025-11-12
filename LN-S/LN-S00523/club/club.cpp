#include<bits/stdc++.h>
using namespace std;
struct asd{
    int n[4];

    int operator[](int i){
        return n[i];
    }
};
bool cmp_a(asd a, asd b){
    return a[1] > b[1];
}
asd a[101000];
void solve(void){
    //多测记得清空

    int N;
    scanf("%d", &N);
    bool matches_sub_A = 1;
    for(int i = 1; i <= N; i++){
        scanf("%d%d%d", &a[i].n[1], &a[i].n[2], &a[i].n[3]);

        if(a[i][2] != 0 || a[i][3] != 0) matches_sub_A = 0;
    }
    //先把子任务A过了
    if(matches_sub_A){
        sort(a + 1, a + N + 1, cmp_a);
        int ttal = 0;
        for(int i = 1; i <= N / 2; i++){
            ttal += a[i][1];
        }
        printf("%d\n", ttal);
        return;
    }

    //测试点1
    if(N == 2){
        int am1, am2, bm1, bm2;

        if(a[1][1] >= a[1][2] && a[1][1] >= a[1][3]) am1 = 1;
        else if(a[1][2] >= a[1][3] && a[1][2] >= a[1][1]) am1 = 2;
        else if(a[1][3] >= a[1][2] && a[1][3] >= a[1][1]) am1 = 3;

        int ai1 = am1%3+1, ai2 = (am1+1)%3+1;
        am2 = (ai1 > ai2) ? ai1 : ai2;


        if(a[2][1] >= a[2][2] && a[2][1] >= a[2][3]) bm1 = 1;
        else if(a[2][2] >= a[2][3] && a[2][2] >= a[2][1]) bm1 = 2;
        else if(a[2][3] >= a[2][2] && a[2][3] >= a[2][1]) bm1 = 3;

        ai1 = am2%3+1, ai2 = (am2+1)%3+1;
        bm2 = (ai1 > ai2) ? ai1 : ai2;

        if(am1 != bm1){
            int res = a[1][am1] + a[2][bm1];
            printf("%d\n", res);
            return;
        }

        int res = max(a[1][am1] + a[2][bm2], a[1][am2] + a[2][bm1]);
        printf("%d\n", res);
        return;
    }
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        solve();
    }

    return 0;
}
