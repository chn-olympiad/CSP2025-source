#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[5005],f[5005][5005],p,ans;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1),m=a[n];
    f[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++)
            if(j<a[i])
                f[i][j]=f[i-1][j];
            else
                f[i][j]=(f[i-1][j]+f[i-1][j-a[i]])%mod;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            f[i][j]=(f[i][j]+f[i][j-1])%mod;
    p=4;
    for(int i=3;i<=n;i++)
    {
        ans=(1LL*ans+p-f[i-1][a[i]]+mod)%mod;
        p=p*2LL%mod;
    }
    cout<<ans;
    return 0;
}
/*
g++ polygon.cpp -o polygon
polygon.exe

//freopen("polygon.in","r",stdin);
//freopen("polygon.out","w",stdout);
//freopen("polygon.in","r",stdin);
//freopen("polygon.out","w",stdout);
//freopen("polygon.in","r",stdin);
//freopen("polygon.out","w",stdout);
//freopen("polygon.in","r",stdin);
//freopen("polygon.out","w",stdout);
//freopen("polygon.in","r",stdin);
//freopen("polygon.out","w",stdout);
*/
