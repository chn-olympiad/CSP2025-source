#include<bits/stdc++.h>
using namespace std;
int a[5002];
int n;
int tans;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    int mx=pow(2,n)-1;
    for(int i=0;i<=mx;i++)
    {
        int nmx=0,sum=0,x=i,ii=0,ans=0;
        while(x!=0)
        {
            ii++;
            if(x%2)
            {
                sum++;
                if(nmx<a[ii])
                {
                    ans+=nmx;
                    nmx=a[ii];
                }
                else
                {
                    ans+=a[ii];
                }
            }
            x/=2;
        }
        if(sum>=3&&ans>nmx) tans=(tans+1)%998244353;
    }
    printf("%d",tans);
    return 0;
}
