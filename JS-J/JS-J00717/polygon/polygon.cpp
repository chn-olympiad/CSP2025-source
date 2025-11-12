#include<bits/stdc++.h>
using namespace std;
const int N=5003;
long long n,a[N];
long long c[N][N];
long long sum[N];
long long ans=0;
long long mod=998244353,cnt=0;
void cala(long long MAX)
{
    for(int i=1;i<=MAX;i++)
    {
        c[i][i]=c[i][0]=1;
        c[i][1]=i;
    }
    for(int i=1;i<=MAX;i++)
    {
        for(int j=1;j<i;j++)
        {
            c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }
}
void dfs(long long x,long long m,long long v,long long big,long long sum,long long num)
{
    if(sum>big)
    {
        //cout<<x<<" "<<m<<" "<<v<<" "<<big<<" "<<sum<<endl;
        cnt++;
        return ;
    }
    else if(num==v+1)
    {
        return;
    }
    else
    {
        for(int i=x;i<=m;i++)
        {
            dfs(i+1,m,v,big,sum+a[i],num+1);
        }
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    cala(n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    sort(a+1,a+1+n);
    for(int i=3;i<=n;i++)
    {
        int pos=-1;
       for(int j=1;j<i;j++)
        {
            if(sum[j]>a[i])
            {
                pos=j;
                break;
            }
        }
        if(pos==-1)continue;
        long long cnt1=0;
        for(int j=2;j<pos;j++)
        {
            cnt=0;
            dfs(1,i-1,j,a[i],0,1);
            cnt1+=cnt;
            //cout<<j<<" "<<cnt<<endl;
        }
        for(int j=pos;j<=i-1;j++)
        {
            cnt1+=c[i-1][j];
        }
        ans=(ans+cnt1)%mod;
        //cout<<pos<<" "<<ans<<endl;
    }
    printf("%lld",ans);
    return 0;
}
