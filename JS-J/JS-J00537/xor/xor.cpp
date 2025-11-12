#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

int n, k;
int a[N];
int res = 0;
int num_1, num_0;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    bool flag = true, f = true;
    for (int i = 1; i <= n; i ++ ) {
        scanf("%d",&a[i]);
        if (a[i] != 1) flag = false;
        if (a[i] == 1) num_1 ++ ;
        if (a[i] == 0) num_0 ++ ;
    }
    if (flag && k == 0) {
        res = n / 2 * 2;
        printf("%d\n", res);
        return 0;
    }
    if (k == 0) {
        if (num_1 &1 == num_0 &1 && num_0 &1 == 1)
            printf("%d\n", num_1 + num_0 - 1);
        else if (num_1 &1 == 0 && num_0 &1 == 0)
            printf("%d\n", num_0 + num_1);
        else if (num_1 &1 == 1 && num_0 &1 == 0)
            printf("%d\n", num_1 + num_0 - 1);
        else
            printf("%d\n", num_0 + num_1);
        return 0;
    }
    if (k == 1) {
        if (num_1 &1 == num_0 &1 && num_0 &1 == 1)
            printf("%d\n", num_1 + num_0 );
        else if (num_1 &1 == 0 && num_0 &1 == 0)
            printf("%d\n", num_0 + num_1 - 1);
        else if (num_1 &1 == 1 && num_0 &1 == 0)
            printf("%d\n", num_1 + num_0);
        else
            printf("%d\n", num_0 + num_1 - 1);
        return 0;
    }
    printf("%d\n", n);
    return 0;
}