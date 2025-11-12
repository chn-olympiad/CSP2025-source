#include<bits/stdc++.h>
using namespace std;
const int N=1048580;
int n,k,ans=0,osum,ybj=1;
int a[N],dp[N][2];
void f(int sum,int dq,int ci)
{
    if(dq==n)
    {
        sum=sum^a[n];
        if(sum==k)
            ans=max(ans,ci+1);
        return;
    }
    if(sum==k)
        f(a[dq+1],dq+1,ci+1);
    f(sum^a[dq],dq+1,ci);
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]=0)
            osum++;
        if(a[i]!=1)
            ybj=0;
    }
    if(k==0)
    {
        printf("%d",osum);
        return 0;
    }
    if(ybj==1)
    {
        if(k==1)
            printf("%d",n);
        if(k==0)
            printf("%d",n/2);
        else
            printf("0");
        return 0;
    }
    dp[1][1]=a[1];dp[1][0]=-1;
    int sum=a[1];
    printf("%d",ans);
    return 0;
}