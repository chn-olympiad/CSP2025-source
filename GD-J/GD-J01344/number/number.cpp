#include <cctype>
#include <cstdio>
#define MAXN 1000003
using namespace std;

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    static char str[MAXN];
    int tot[10] = {};
    scanf("%s", str);
    for (const char *p = str; *p; ++p)
        if (isdigit(*p))
            ++tot[*p - '0'];
    for (int i = 9; i >= 0; --i)
        while (tot[i]--)
            putchar(i + '0');
    return 0;
}
