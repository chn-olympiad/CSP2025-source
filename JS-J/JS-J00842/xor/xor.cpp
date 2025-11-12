#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int st[N][25];
int lg[N],a[N],flag,flag2,ans;
int n,k;
int read()
{
    int f = 1,x = 0;
    char c = getchar();
    while(!isdigit(c))
        f = c == '-' ? -1 : 1,c = getchar();
    while(isdigit(c))
        x = (x << 3) + (x << 1) + (c ^ 48),c = getchar();
    return x * f;
}
int query(int jobl,int jobr)
{
    int ans = 0;
    int k = lg[jobr-jobl+1];
    ans ^= st[jobl][k];
    int l = jobl + (1 << k);
    while(k && l <= jobr)
    {
        k--;
        ans ^= st[l][k];
        l = l + (1<<k);
    }
    return ans;
}
int c[N];
bool vis[N];
int lowbit(int x)
{
    return (-x) & x;
}
void upd(int x)
{
    while(x <= n)
    {
        c[x]++;
        x += lowbit(x);
    }
}
int q(int x)
{
    int ans=0;
    while(x)
    {
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
}
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    n = read();
    k = read();
    for(int i=1;i<=n;i++)
    {
        a[i] = read();
        if(a[i] != 1) flag=1;
        if(a[i] != 1 && a[i] != 0) flag2 = 1;
    } 
    if(!flag)
    {
        if(k == 1)
        {
            printf("%lld\n",n);
        }
        else
            printf("%lld\n",n/2);
        return 0;
    }
    if(!flag2)
    {
        int ans = 0;
        if(k == 1)
        {
            for(int i=1;i<=n;i++)
                if(a[i] == 1)
                    ans++;
            printf("%lld\n",ans);
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i] == 0) ans++;
                else
                {
                    if(a[i+1] == 1)
                        ans++,i = i+1;
                }
            }
            printf("%lld\n",ans);
        }
        return 0;
    }
    for(int i=2;i<=n;i++)
        lg[i] = lg[i>>1] + 1;
    for(int i=1;i<=n;i++)
        st[i][0] = a[i];
    for(int j=1;j<=lg[n];j++)
    {
        for(int i=1;i + (1 << j) - 1 <= n;i++)
        {
            st[i][j] = st[i][j-1] ^ st[i + (1 << (j-1))][j-1];
        }
    }
    for(int len = 1;len <= n;len++)
    {
        for(int i=1;i+len-1 <= n;i++)
            if(query(i,i+len-1) == k)
            {
                bool ok=true;
                for(int j=i;j<=i+len-1;j++)
                {
                    if(vis[j]){
                        ok=0;
                        break;
                    }
                }
                if(!ok) continue;
                ans++;
                for(int j=i;j<=i+len-1;j++)
                    vis[j] = true;
            }
    }
    cout<<ans<<endl;
    return 0;
}