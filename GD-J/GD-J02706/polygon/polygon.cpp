/*
CSP-j AK I 
*/ 
#include<bits/stdc++.h>
using namespace std;
const int N=5007,MOD=998244353;
long long n,m,i,j,k,dp[N][N],mi[N],a[N],ans;
long long f(long long jd,long long num)
{
    if(jd<0&&num<0) return 1;
    else if(jd<0&&num>=0) return 0;
    else if(num<0) return mi[jd+1];
    if(dp[jd][num]!=-1) return dp[jd][num];
    dp[jd][num]=(f(jd-1,num-a[jd])+f(jd-1,num))%MOD;
    return dp[jd][num];
}
int main()
{
    mi[0]=1;
    for(i=1;i<N;i++) mi[i]=(mi[i-1]*2)%MOD;
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(i=0;i<N;i++) for(j=0;j<N;j++) dp[i][j]=-1;
    ans=0;
    for(i=1;i<n-1;i++)
    {
        ans+=f(i,a[i+1]);
        ans%=MOD;
    }   
    cout<<ans;
    return 0;
}
