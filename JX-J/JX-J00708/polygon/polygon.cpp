#include<bits/stdc++.h>
using namespace std;
long long a,c[10000],h[10000],sum;
void yu(long long kl,long long ans,long long zy)
{
    if(kl<0)
    {
        if(zy>ans)
            sum++;
        sum=sum%998244353;
        return;
    }
    zy+=c[kl];
    yu(kl-1,ans,zy);
    zy-=c[kl];
    yu(kl-1,ans,zy);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>a;
    for(int i=0;i<a;i++)
        cin>>c[i];
    sort(c+0,c+a);
    h[0]=c[0];
    for(int i=1;i<a;i++)
        h[i]=c[i]+h[i-1];
    for(long long i=2;i<a;i++)
    {
        yu(i-1,c[i],0);
    }
    cout<<sum;
}
