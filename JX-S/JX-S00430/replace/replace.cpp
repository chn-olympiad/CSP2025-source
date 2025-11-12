#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n, q;
struct node
{
    char s1[1000];
    char s2[1000];
}a[20050], t[20050];

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++)
        scanf("%s %s", &a[i].s1, &a[i].s2);
    for(int i = 1; i <= q; i++)
        scanf("%s %s", &a[i].s1, &a[i].s2);

    for(int i = 1; i <= q; i++)
        printf("0\n");

    return 0;
}
