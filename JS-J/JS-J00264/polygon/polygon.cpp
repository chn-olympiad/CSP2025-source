#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int n;
int a[5100];
int MOD=998244353;
ll sum=0;
bool vis[30];
void dfs(int dep,int h,int sum1,int maxn,int maxid)
{
    if (dep>h)
    {
        if (sum1>2*maxn)
        {
            sum++;
            sum%=MOD;
        }
        return;
    }
    for (int i=1;i<=n;i++)
    {
        if (!vis[i] && maxid<i)
        {
            vis[i]=1;
            dfs(dep+1,h,sum1+a[i],max(maxn,a[i]),i);
            vis[i]=0;
        }
    }
}
ll C(int n,int m)
{
    ll h1=1;
    for (int i=m;i>=m-n+1;i--)
    {
        h1*=i;
        h1%=MOD;
    }
    ll h2=1;
    for (int i=n;i>=1;i--)
    {
        h2*=i;
        h2%=MOD;
    }
    return h1/h2;
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    if (n<3)
    {
        cout << 0;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if (n==3)
    {
        int a,b,c;
        cin >> a >> b >> c;
        int sum=a+b+c;
        if (max({a,b,c})*2<sum)
        {
            cout << 1;
            fclose(stdin);
            fclose(stdout);
            return 0;
        }
        else
        {
            fclose(stdin);
            fclose(stdout);
            cout << 0;
            return 0;
        }
    }
    bool flag=1;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        if (a[i]!=1)
        {
            flag=0;
        }
    }
    if (flag)
    {
        ll sum=0;
        for (int i=3;i<=n;i++)
        {
            sum+=C(i,n);
            sum%=MOD;
        }
        cout << sum;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    a[0]=-1;
    if (n<=20)
    {
        for (int i=3;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            dfs(1,i,0,0,0);
        }
        cout << sum;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
