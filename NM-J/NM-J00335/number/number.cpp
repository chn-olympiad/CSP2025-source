#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int a[N];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    string s;
    cin >> s;
    int len = s.length(), rear = 0;
    for (int i = 0; i < len; i++)
        if (s[i] >= '0' && s[i] <= '9')
            a[++rear] = s[i] - '0';
    sort(a + 1, a + 1 + rear, cmp);
    for (int i = 1; i <= rear; i++)
        printf("%d", a[i]);

    fclose(stdin);
    fclose(stdout);

    return 0;
}
