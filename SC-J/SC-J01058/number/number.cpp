#include <cstdio>
#include <algorithm>
using namespace std;
struct IO {
    IO () {
        freopen("number.in", "r", stdin);
        freopen("number.out", "w", stdout);
    }
    ~IO () {
        fclose(stdin);
        fclose(stdout);
    }
} io;
int t[15];
bool isNum (char c) {
    return c <= '9' && c >= '0';
}
bool isChar (char c) {
    return c <= 'z' && c >= 'a';
}
int main () {
    char c = getchar();
    while (!isNum(c) && !isChar(c)) c = getchar();
    while (isNum(c) || isChar(c)) {
        if (isNum(c)) t[c - '0']++;
        c = getchar();
    }
    for (int i = 9; i >= 0; --i)
        while (t[i]) putchar(i + '0'), --t[i];
    puts("");
    return 0;
}