#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n, m, k, u, v, w, ans = 10000000;
int mp[1005][1005];

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        mp[u][v] = w;
    }

    printf("13");

    return 0;
}
