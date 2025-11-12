#include <cstdio>

constexpr int MAXN = 1e6 + 10;

char str[MAXN];

int num[10];

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);


    scanf("%s", str);

    for(const char *pc = str; *pc; ++pc)
        if(*pc >= '0' && *pc <= '9')
            ++num[*pc - '0'];

    for(int i = 9; i >= 0; --i)
        while(num[i]--)
            putchar('0' + i);

}