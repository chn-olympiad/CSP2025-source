#include <bits/stdc++.h>
using namespace std;
struct qj
{
    int l,r;
}a3[500005];
int n,k,cur,answ,a2[25][500005],dp[500005];
bool a[25][500005],ans[25];
bool calc(int l,int r)
{
    for(int i = 0;i < 20;i++)
    {
        if(abs(a[i][r] - a[i][l - 1]) != ans[i])
        {
            return 0;
        }
    }
    return 1;
}
bool cmp(qj x,qj y)
{
    return x.r < y.r;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    while(k)
    {
        ans[cur++] = k % 2;
        k /= 2;
    }
    cur = 0;
    for(int i = 1;i <= n;i++)
    {
        int s;
        scanf("%d",&s);
        for(int j = 0;j < 20;j++)
        {
            a[j][i] = s % 2;
            s /= 2;
        }
    }
    for(int i = 0;i < 20;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            a[i][j] = (a[i][j - 1] + a[i][j]) % 2;
        }
    }
    for(int l = 1;l <= n;l++)
    {
        for(int r = l;r <= n;r++)
        {
            if(calc(l,r))
            {
                a3[++cur].l = l;
                a3[cur].r = r;
            }
        }
    }
    sort(a3 + 1,a3 + cur + 1,cmp);
    int la = 0;
    for(int i = 1;i <= cur;i++)
    {
        if(a3[i].l > la)
        {
            answ++;
            la = a3[i].r;
        }
    }
    printf("%d",answ);
    return 0;
}
