#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;

char s[N];

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    sort(s + 1, s + 1 + n);
    for (int i = n;i >= 1;-- i)
        if (s[i] >= '0' && s[i] <= '9')
            putchar(s[i]);
    printf("\n");
    fclose(stdin);
    fclose(stdout);

    return 0;
}