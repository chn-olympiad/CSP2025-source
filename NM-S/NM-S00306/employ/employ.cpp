#include <bits/stdc++.h>
using namespace std;
int n,m,c[505],f[505][505],ans=1;
string s;
char s_[505];
int main()
{
    freopen('employ.in','r',stdin);
    freopen('employ.out','w',stdout);
    cin >> n >> m;
    cin >> s;
    for (int i=1;i<=n;i++)
    {
        cin >> c[i];
        s_[i]=s[i-1];
        f[n][1]=n;
        f[n][n]=1;
    }
    for (int i=2;i<=n;i++)
    {
        for (int j=2;j<=m;j++)
        {
            f[n][m]=f[n][m-1]+f[n-1][m-1];
        }
    }
    for (int i=2;i<=f[n][m];i++)
    {
        ans*=i;
    }
    cout << ans;
    return 0;
}
