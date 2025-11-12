#include<bits/stdc++.h>
using namespace std;
const int NR = 5e2;
const int MR = 18;
const int P = 998244353;
char s[NR + 10];
int a[NR + 10];
int p[NR + 10];

int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
    }
    for(int i = 1;i <= n;i++){
        p[i] = i;
    }
    int ans = 0;
    do{
        int cnt = 0;
        for(int i = 1;i <= n;i++){
            // printf("p[%d]=%d cnt=%d\n", i, p[i], cnt);
            if(s[i] == '1' && (i - 1 - cnt) < a[p[i]]){
                cnt++;
            }
        }
        if(cnt >= m) ans++;
        // printf("\n");
    }while(next_permutation(p + 1, p + 1 + n));
    printf("%d\n", ans);
    return 0;
}
/*
cd ~/employ && g++ employ.cpp -O2 -o employ && ./employ

3 2
101
1 1 2

*/