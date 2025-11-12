#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
string str;
int a[15] = {0};
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> str;
    int len = str.length();
    for(int i = 0; i < len; i++) {
        if('0' <= str[i] && str[i] <= '9')
            a[int(str[i] - '0')]++;
    }
    for(int i = 9; i >= 0; i--) {
        for(int j = 1; j <= a[i]; j++) {
            printf("%d", i);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
