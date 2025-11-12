#include<iostream>
#include<cmath>
#include<algorithm>
#define mod 998244353
using namespace std;
long long n,a[5001],f[5001][5001],g[5001];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
//  freopen(".in","r",stdin);
//  freopen(".out","w",stdout);
    freopen("polygen.in","r",stdin);
    freopen("polygen.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==3)
    {
        if(a[1]+a[2]+a[2]>2*max(max(a[1],a[2]),a[3])) cout<<"1\n";
        else cout<<"0\n";
        return 0;
    }
    f[0][0]=1;
    for(int i=1;i<=5000;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0||j==i) f[i][j]=1;
            else f[i][j]=(f[i-1][j]+f[i-1][j-1])%mod;

        }
        for(int j=3;j<=i;j++) g[i]+=f[i][j];g[i]%=mod;
    }
    cout<<g[n]<<endl;
    return 0;
}
//luogu914813 Undercraft
//acta est fabula,plaudite
//xi wang bu yao AFO
//shun bian ji lian yong yuan de vivid/stasis
//hao xiang 2026nian jiu ting gen le
//csp-j JS-J00493 csp-s JS-S00500
//chu sai -j 98 -s 72
//di 3 nian le
//ming tian gai si de dong tai shi shi yan zhong xue jiu yao yue kao
//tmd,zhe xiang dang yu cspj-s day 2
//csp-j 2025
//11:05 mei jiu le,deng zhe AFO le,0pts,yong le rand
//11:08 gai le yi xia ,gu ji 24pts
//11:34 gu ji 36pts
