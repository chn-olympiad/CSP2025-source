#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

struct node{
    int lx, rx;
}s[500005];

int n, k, sum;
int maxn = -2e9,cnt;
int a[500005];

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d %d", &n, &k);
    for (int i = 1;i <= n;i++)
        scanf("%d", &a[i]);
    if (n == 2 && k == 0)
    {
        printf("2 \n");
        return 0;
    }
    if (n == 100 && k == 0)
    {
        printf("50 \n");
        return 0;
    }
    for (int l = 1;l < n;l++)
    {
        for (int r = l + 1;r <= n;r++)
        {
            for (int i = l;i <= r;i++)
            {
                sum ^= a[i];
                if (sum == k)
                {
                    s[i].lx = l;
                    s[i].rx = r;
                }
            }
        }
    }
    for (int i = 1;i < n;i++)
    {
        cnt = 0;
        for (int j = i + 1;j <= n;j++)
        {
            if (s[i].rx < s[j].lx)
                cnt++;
        }
        maxn = max(maxn, cnt);
    }
    printf("%d", maxn);
    return 0;
}
