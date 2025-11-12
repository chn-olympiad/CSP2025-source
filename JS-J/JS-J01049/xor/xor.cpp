#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
typedef long long LL;
const LL N=5e5+8;
LL n,k,a[N],t,ans=0;
LL f(LL fl,LL pos)
{
    for(LL i=pos;i<=n;i++)
    {
        for(LL j=i;j<=n;j++)
        {
            t=a[i];
            for(LL l=i+1;l<=j;l++)
            {
                t^=a[l];
            }
            if(t==k)
            {
                return f(fl+1,j+1);
            }
        }
    }
    return fl;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(LL i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    ans=max(ans,f(0,1));
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
