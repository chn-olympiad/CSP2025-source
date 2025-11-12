#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int c[600][600];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,sum1=0;
    cin >> n >> m;
    for (int i=0;i<=n;i++)c[i][i]=1,c[i][0]=1,c[0][i]=1;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<i;j++)
        {
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        }
    }
    for (int i=1;i<=n;i++)
    {
        char cc;
        cin >> cc;
        sum1+=cc-'0';
    }
    if (n==m)
    {
        if (sum1==n)cout << 1;
        else cout << 0;
        return 0;
    }
    if (sum1<m)
    {
        cout << 0;
        return 0;
    }
    if (m==1)
    {
        if (sum1==0)
        {
            cout << 0;
            return 0;
        }
        cout << c[n][sum1];
        return 0;
    }
    cout << 1;
    return 0;
}
