#include<bits/stdc++.h>
std::string s;
char a[100001];
int cnt;
bool cmp(char x, char y) {
    return x > y;
}
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    std::cin >> s;
    for (int i = 0; s[i]; i++)
        if (s[i] >= '0' && s[i] <= '9')
            a[cnt++] = s[i];
    std::sort(a, a + cnt, cmp);
    std::cout << a;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
