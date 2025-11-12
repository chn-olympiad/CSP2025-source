#include <bits/stdc++.h>
using namespace std;
long long n,d,i,f=1,fa=0;
long long a[5015];
bool b[5015];
void dfs(long long n1,long long l,long long m)
{
    if (l>2*m&&n1==i)
    {
        d++;
        d%=998244353;
        return ;
    }
    if (n1==i)
    {
        return ;
    }
    for (long long q=f;q<=n;q++)
    {
        if (!b[q])
        {
            b[q]=1;
            f=q;
            long long f1=f;
            dfs(n1+1,l+a[q],max(m,a[q]));
            f=f1;
            b[q]=0;
        }
    }
    return ;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
        fa=max(fa,a[i]);
    }
    for (i=3;i<=n;i++)
    {
        f=1;
        dfs(0,0,0);
    }
    cout<<d;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
