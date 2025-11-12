#include<bits/stdc++.h>
using namespace std;
const int N=5000+10,Mo=998244353;
long long n,ans=0,f=0,maxn=0;
int a[N],b[N];
int c[N],q[N];
int dp[N][N],mx;
long long m[N];
void dip(int dep,int s,int m,int ct)
{
    if(dep>n)
    {
        if(s>m*2&&ct>=3)
        {
            /*for(int i=1;i<=n;i++)
            {
                if(b[i]==1)
                {
                    cout<<i<<" ";
                }
            }
            cout<<endl;*/
            ans++;
            ans=ans%Mo;
        }
    }
    else
    {
        dip(dep+1,s,m,ct);
        b[dep]=1;
        dip(dep+1,s+a[dep],max(m,a[dep]),ct+1);
        b[dep]=0;
    }
}
int main()
{
   freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        //a[i]=1;
       scanf("%d",&a[i]);
       if(a[i]!=1)
       {
           f=1;
       }
    }
    if(f==0)
    {
        __int128 h=n;
        __int128 sum=h*(h-1)*(h-2)/(1*2*3);
        sum=sum%Mo;
        ans=ans%Mo;
        ans+=sum;
        for(__int128 i=3;i<n;i++)
        {
            sum=sum*(h-i)/(i+1);
            sum=sum%Mo;
            ans+=sum;
            ans=ans%Mo;
        }
        cout<<ans;
        return 0;
    }
    else if(n<=20)
    {
        dip(1,0,-1,0);
        cout<<ans;
        return 0;
    }
    else
    {
        memset(dp,0,sizeof(dp));
        sort(a+1,a+n+1);
        maxn=a[n];
        for(int i=1;i<=n;i++)
        {
            //cout<<a[i]<<" ";
            int mux=0;
            for(int j=1;j<=maxn;j++)
            {
                if(a[i]<=j)
                {
                    //cout<<"yui";
                    dp[i][j]++;
                    dp[i][j]+=dp[i-1][j-a[i]];
                    dp[i][j]=dp[i][j]%Mo;
                }
                dp[i][j]+=dp[i-1][j];
                dp[i][j]=dp[i][j]%Mo;
            }
            dp[i][maxn+1]=mux;
        }
        /*for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=maxn;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        for(int i=1;i<=n;i++)
        {
            m[i]=m[i-1]*2+1;
            m[i]=m[i]%Mo;
        }
        for(int i=1;i<=n;i++)
        {
            int sum=0;
            sum=dp[i-1][a[i]];
            /*if(i>1)
            {
                sum=sum-dp[i-2][a[i]];
            }*/
            if(sum-m[i]>0) m[i]+=Mo;
            ans+=m[i-1]-sum;
            ans=ans%Mo;
            //cout<<ans<<" ";
        }
        cout<<ans;
        //cout<<ans-1-n*(n-1)/2-n;
        return 0;
    }
    //cout<<ans;
    return 0;
}
