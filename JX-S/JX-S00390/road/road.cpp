//xjz0918 CSP-S2025 RP++
//FROM GAN NAN SHI DA FU ZHONG
#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000010],v[1000010],w[1000010];
long long ans=0;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
        ans=ans+w[i];
    }
    cout<<ans<<endl;
    return 0;
}
