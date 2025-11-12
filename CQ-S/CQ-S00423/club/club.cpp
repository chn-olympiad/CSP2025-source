#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
namespace Read{
    inline int read(){
        int f = 0, d = 1; char op;
        while(op = getchar(), !isdigit(op)) if(op == '-') d = - 1;
        while(isdigit(op)) f = (f << 1) + (f << 3) + (op ^ 48), op = getchar();
        return f * d;
    }
} using namespace Read;
namespace YYY{
    const int N = 1e5 + 10, INF = 0x3f3f3f3f;
    int n, a[3][N], cnt[3], val[N];
    int tmp[N], idx_tmp;
    void sol(){
        cnt[0] = cnt[1] = cnt[2] = 0;
        n = read();
        int Sum = 0; idx_tmp = 0;
        for(int i = 1; i <= n; i ++ ){
            for(int j = 0; j < 3; j ++ ){
                a[j][i] = read();
            }
            if(a[0][i] >= a[1][i] && a[0][i] >= a[2][i]){
                cnt[0] ++ ; val[i] = 0; Sum += a[0][i];
            }
            else if(a[1][i] >= a[0][i] && a[1][i] >= a[2][i]){
                cnt[1] ++ ; val[i] = 1; Sum += a[1][i];
            }
            else{
                cnt[2] ++ ; val[i] = 2; Sum += a[2][i];
            }
        }
        if(max(cnt[0], max(cnt[1], cnt[2])) <= n / 2) cout<<Sum<<'\n';
        else{
            int op;
            if(cnt[0] > n / 2) op = 0;
            else if(cnt[1] > n / 2) op = 1;
            else op = 2;
            for(int i = 1; i <= n; i ++ ){
                if(val[i] == op){
                    int temp = INF;
                    for(int j = 0; j < 3; j ++ ){
                        if(j != op) temp = min(temp, a[op][i] - a[j][i]);
                    }
                    tmp[ ++ idx_tmp] = temp;
                }
            }
            sort(tmp + 1, tmp + 1 + idx_tmp);
            for(int i = 1; i <= cnt[op] - (n / 2); i ++ ) Sum -= tmp[i];
            cout<<Sum<<'\n';
        }
    }
    signed main(){
        int T; T = read();
        while(T -- ) sol();
        return 0;
    }
}
signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    return YYY::main();
}
/*
g++ club.cpp -o club -std=c++14 -O2 -Wall -lm -Wl,--stack=2000000000 && .\club.exe < a.in > a.out

g++ club.cpp -o club -std=c++14 -O2 -Wall -lm -Wl,--stack=2000000000
.\club.exe < D:\CQ-S00423\club\club1.in > a.out && fc a.out D:\CQ-S00423\club\club1.ans
.\club.exe < D:\CQ-S00423\club\club2.in > a.out && fc a.out D:\CQ-S00423\club\club2.ans
.\club.exe < D:\CQ-S00423\club\club3.in > a.out && fc a.out D:\CQ-S00423\club\club3.ans
.\club.exe < D:\CQ-S00423\club\club4.in > a.out && fc a.out D:\CQ-S00423\club\club4.ans
.\club.exe < D:\CQ-S00423\club\club5.in > a.out && fc a.out D:\CQ-S00423\club\club5.ans

*/