# include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 510;
char s[N];
int a[N],c[N],b[N],x[N],vis[N],cnt[N];
int n,m;
const int mod = 998244353;
int ans;
int jc[N];
void dfs(int dep)
{
    if(dep == n+1)
    {
        // for(int i = 1;i <= n;i++) cout << x[i] << " ";
        // cout << endl;
        for(int i = 1;i <= n;i++) cnt[i] = 0;
        int pp = 0;
        for(int i = 1;i <= n;i++)
        {
            cnt[++pp] = c[x[i]];
        }
        int res0 = 0,ac = 0;
        for(int i = 1;i <= n;i++)
        {
           if(res0 >= cnt[i])
           {
               res0++;
               continue;
           }
           if(b[i] == 1) ac++;
           else res0++;
        }
        if(ac >= m) 
        {
            ans++;
        }
        return ;
    }
    for(int i = 1;i <= n;i++)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            x[dep] = i;
            dfs(dep+1);
            vis[i] = 0;
        }
    }
}
int qpow(int a,int b)
{
    int res = 1;
    while(b != 0)
    {
        if(b & 1)
        {
            res = res*a%mod;
        }
        a = a*a%mod;
        b >>= 1;
    }
    return res;
}
int ny(int x)
{
    return qpow(x,mod-2);
}
int C(int n,int m)
{
    return jc[n]*ny(jc[m]*jc[n-m]%mod)%mod;
}
signed main (){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    scanf("%s",s);
    int len = strlen(s);
    int tot = 0;
    int flag = 1;
    for(int i = 0;i < len;i++)
    {
        b[++tot] = (int)(s[i]-'0');
        if(b[tot] == 0) flag = 0;
    }
    int xx = 0 ;
    for(int i = 1;i <= n;i++)
    {
        scanf("%lld",&c[i]);
        if(c[i] == 0) xx++;
    }
    if(n <= 18)
    {
        dfs(1);
        printf("%lld\n",ans);
    }
    else if(m == n)
    {
        jc[0] = 1;
        for(int i = 1;i <= N-5;i++) jc[i] = jc[i-1]*i%mod;
        for(int i = 1;i <= n;i++)
        {
            if(b[i] == 0 || c[i] == 0)
            {
                return printf("0\n"),0;
            }
        }
        printf("%lld\n",jc[n]);
    }
    else if(m == 1)
    {
        
    }
    else if(flag == 1)
    {
        // jc[0] = 1;
        // for(int i = 1;i <= N-5;i++) jc[i] = jc[i-1]*i%mod;
        
    }
    return 0;   
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/