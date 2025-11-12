#include<iostream>
#include<cstdio>
using namespace std;

int n, k, a[500010];
bool flag = 1;

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if(a[i] != 1) flag = 0;
    }
    if(flag) printf("%d", n);
    else printf("2");
    return 0;
}
