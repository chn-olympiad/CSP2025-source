#include<bits/stdc++.h>
using namespace std;
const int mo=998244353;
const int N=505;
int n,m;
int a[N],c[N],pr[N];
int cc[N][N],pre[N],suf[N];
int dp[N][N][N],num[N];
long long fac[N];
int add(int x,int y)
{
    int ans=x+y;
    if(ans>=mo)return ans-mo;
    return ans;
}
long long C(int n,int m)
{
    if(n<0||m<0||n<m)return 0;
    return cc[n][m];
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cc[0][0]=1;
    for(int i=1;i<=500;i++)
    {
        cc[i][0]=1;
        for(int j=1;j<=i;j++)
        {
            cc[i][j]=add(cc[i-1][j],cc[i-1][j-1]);
        }
    }
    cin>>n>>m;
    fac[0]=1;
    for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mo;
    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;
        a[i]=c-'0';
        pr[i]=pr[i-1]+(a[i]==0);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        pre[c[i]]++;
        suf[c[i]]++;
        num[c[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        pre[i]+=pre[i-1];
    }
    for(int i=n;i>=1;i--)
    {
        suf[i]+=suf[i+1];
    }
    dp[0][0][0]=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)
        {
            memcpy(dp[i],dp[i-1],sizeof(dp[i]));
            for(int j=0;j<=n;j++)
            {
                for(int k=n-j;k>=0;k--)
                {
                    if(dp[i][j][k]==0)continue;
                    int cc=i-(j+k);
                    if(cc<0)continue;
                    for(int ll=1;ll<=min(j,num[cc]);ll++)
                    {
						//cerr<<C(num[cc],ll)%mo*C(j,ll)%mo<<"??\n";
                        dp[i][j-ll][k+ll]=add(dp[i][j-ll][k+ll],1ll*dp[i][j][k]*C(num[cc],ll)%mo*C(j,ll)%mo*fac[ll]%mo);
                    }
                }
            }
        }
        else
        {
            //case 1 another 1
            for(int j=0;j<=i;j++)
            {
                for(int k=0;k+j<=i;k++)
                {
                    if(dp[i-1][j][k]==0)continue;
                    dp[i][j+1][k]=add(dp[i][j+1][k],dp[i-1][j][k]);
                }
            }
            //case 2 another 0
            for(int j=0;j<=i;j++)
            {
                for(int k=0;k<=i;k++)
                {
                    if(dp[i-1][j][k]==0)continue;
                    int cc=i-(j+k);
                    if(cc<0)continue;
                    for(int ll=0;ll<=min(j,num[cc]);ll++)
                    {
                        if(pre[cc-1]<(i-(j+pr[i])-1))continue;
                        //cerr<<cc<<' '<<pre[cc-1]<<' '<<(pre[cc-1]-(i-(j+pr[i])-1))<<"!!\n";
                        dp[i][j-ll][k+ll]=add(dp[i][j-ll][k+ll],1ll*dp[i-1][j][k]*C(num[cc],ll)%mo*C(j,ll)%mo*(pre[cc-1]-(i-(j+pr[i])-1))%mo*fac[ll]%mo);
                    }
                }
            }
        }
    }
    //cerr<<dp[4][3][0]<<"??\n";
    long long ans=0;
        for(int j=0;j<=n;j++)
        {
            for(int k=n-j;k>=0;k--)
            {
                if(suf[n-k-j+1]>=j&&(k+j)>=m)
                {
					
                    ans=add(ans,C(suf[n-k-j+1],j)*dp[n][j][k]%mo*fac[j]%mo);
                }
            }
        }
       //cerr<<ans<<"??\n";
        int now=1;
    for(int j=1;j<=n;j++)
    {
        if(a[j]==0)
        {
            ans=ans*now%mo;
            now++;
        }
    }
    cout<<ans<<'\n';
}
