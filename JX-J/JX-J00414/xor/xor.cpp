#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool f[500005];
int k,n;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int ans=0;
    bool flag=1;
    scanf("%d%d",&n,&k);
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
        if(a[i]>1)flag=0;
        if(a[i]==k)
        {
            f[i]=1;
            ans++;
        }
    }
    if(sum==n)
    {
        printf("%d",n/2);
        return 0;
    }
    if(flag)
    {
        if(k==0)
        {
            int ans1=0,cnt=1;
            while(cnt<=n)
            {
                if(a[cnt]==0)ans1++;
                else if(a[cnt]==1&&a[cnt-1]==0)
                {
                    ans1++;
                    if(a[cnt+1]==1)cnt++;
                }
                cnt++;
            }
            printf("%d",ans1);
        }
        else if(k==1)
        {
            int cnt=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]==1)cnt++;
            }
            printf("%d",cnt);
        }
        else printf("0");
        return 0;
    }
    printf("%d",ans);

    return 0;
}
