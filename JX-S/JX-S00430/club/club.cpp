#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int t;
int n, mx;
long long sum;
int a[100050][3] = {0};
int flag[3] = {0};

void dfs(int x, long long ans)
{
    if(x > n)
    {
        sum = max(sum, ans);
        return;
    }
    for(int i = 0; i <= 2; i++)
    {
        if(flag[i] < mx)
        {
            flag[i]++;
            dfs(x + 1, ans + a[x][i]);
            flag[i]--;
        }
    }
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    scanf("%d", &t);
    while(t--)
    {
        sum = 0;
        memset(a, 0, sizeof(a));
        memset(flag, 0, sizeof(flag));

        scanf("%d", &n);
        mx = n / 2;
        for(int i = 1; i <= n; i++)
            for(int j = 0; j < 3; j++)
                scanf("%d", &a[i][j]);

        dfs(1, 0);

        printf("%lld\n", sum);

    }

    return 0;
}
