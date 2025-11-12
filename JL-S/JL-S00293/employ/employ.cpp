#include<bits/stdc++.h>
#define mod 998244353

using namespace std;

int n,m;
char s[100005];
int c[100005],sum;
int fac[100005];

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&c[i]);
    }
    if(m == n)
    {
        printf("0");
        return 0;
    }
    if(s[1] == '1' || m == 1)
    {
        for(int i=1;i<=n;i++)
        {
            if((!c[i]) || sum >= c[i])
            {
                sum++;
            }
        }
        if(n - sum < m)
        {
            printf("0");
            return 0;
        }
        fac[0] =1;
        for(int i=1;i<=n;i++)
        {
            fac[i] = fac[i-1] * i % mod;
        }
        printf("%d",fac[n]);
    }

    return 0;
}
