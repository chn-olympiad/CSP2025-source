#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
string s;
int c[505];
int p[505];
void funA()
{
    long long mul = 1;
    for (int i = 1;i <= n;i++) mul *= i;
    printf("%lld\n",mul);
}
bool cmp(int x,int y)
{
    return (x < y);
}
bool chk(int cur)
{
    for (int i = n - cur + 1;i <= n;i++)
    {
        int v = i - p[i];
        if (c[i] < p[i]) return 0;
    }
    return 1;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d %d",&n,&m);
    cin >> s;
    for (int i = 1;i <= n;i++)
    {
        scanf("%d",&c[i]);
    }
    int cur = -1;
    for (int i = 1;i <= n;i++)
    {
        p[i] = p[i - 1] + int(s[i - 1] - '0');
        if (p[i] == m)
        {
            cur = i;
        }
    }
    if (p[n] == n)
    {
        funA();
        return 0;
    }
    if (cur == -1)
    {
        printf("0\n");
        return 0;
    }
    sort(c + 1,c + n + 1,cmp);
    if (chk(cur))
    {
        long long ans = 1;
        for (int i = cur + 1;i <= n;i++)
        {
            ans *= i - cur;
        }
        printf("%lld\n",ans);
    }
    else
    {
        printf("%d\n",0);
    }
    return 0;
}
