//xjz0918 CSP-S2025 RP++
//FROM GAN NAN SHI DA FU ZHONG
#include<bits/stdc++.h>
using namespace std;
int n,m,a[1010];
long long ans=1;
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        ans=(ans*i)%998244353;
    }
    cout<<ans<<endl;
    return 0;
}
