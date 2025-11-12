#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
char c [N];
int a [N];

int main ()
{
    freopen ("number.in", "r", stdin);
    freopen ("number.out", "w", stdout);
    scanf ("%s", c + 1);
    int n = 0;
    for (int i = 1; c [i] != '\0'; i++)
    {
        if ('0' <= c [i] && c [i] <= '9')
        {
            a [++n] = c [i] - '0';
        }
    }
    sort (a + 1, a + n + 1);
    for (int i = n; i >= 1; i--)
    {
        printf ("%d", a [i]);
    }
    printf ("\n");
    return 0;
}