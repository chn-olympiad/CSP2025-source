#include <cstdio>
#define uint unsigned long long
#define sint long long
const int maxn = 1e6 + 5;
int cnt[20];
char s[maxn];
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    scanf("%s", s + 1);
    int n = 1;
    while(s[n + 1]) n ++;
    for(int i = 1; i <= n; i++) cnt[s[i] - '0'] ++;
    for(int i = 9; i >= 0; i--){
        for(int j = 0; j < cnt[i]; j++) printf("%d", i);
    }
    printf("\n");
    return 0;
}