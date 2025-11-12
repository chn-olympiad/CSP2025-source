#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3;
long long sum[N],a[N],l[N];
long long n,k;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        if(i==1)sum[1]=a[1];
        else sum[i]=sum[i-1]^a[i];
    }
    //cout<<sum[0]<<" ";
    //for(int i=1;i<=n;i++)cout<<sum[i]<<" ";
    long long right=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i-1;j>=right;j--)
        {
            if((sum[i]^sum[j])==k)
            {
                //cout<<i<<" "<<j<<endl;
                if(j+1>right)
                {
                    ans++;
                    right=i;
                    //cout<<right<<endl;
                    break;
                }
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
