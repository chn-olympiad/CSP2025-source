#include <bits/stdc++.h>
using namespace std;
const int N = 510,mod = 998244353;
int n,m,ans,c[N],f[1 << 18][19];
char s[N];
void Add(int &x,int v){x += v;if(x >= mod) x -= mod;}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d%s",&n,&m,s);
    for(int i = 0;i < n;i++) scanf("%d",&c[i]);
    f[0][0] = 1;
    for(int i = 0;i < (1 << n);i++)
    {
        int p = __builtin_popcount(i);
        for(int j = 0,v;j <= p;j++)
        {
            if(!(v = f[i][j])) continue;
            for(int k = 0;k < n;k++)
            {
                if((i >> k) & 1) continue;
                Add(f[i | (1 << k)][j + (s[p] == '1' && p - j < c[k])],v);
            }
        }
    }
    for(int i = m;i <= n;i++) Add(ans,f[(1 << n) - 1][i]);
    printf("%d\n",ans);
    return 0;
}