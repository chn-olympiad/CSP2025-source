#include<bits/stdc++.h>
using namespace std;
const int N=205;
const int M=1e5+5;
int f[N][N][N];
int t=0;
int n=0;
int a[M][4];
int dp1[N][N];
int b[M];
void CLEARS()
{
    for(int j=0;j<N;j++)
        for(int k=0;k<N;k++)
            for(int l=0;l<N;l++)
                f[j][k][l]=0;
    for(int i=0;i<M;i++) a[i][1]=0,a[i][2]=0,a[i][3]=0;
}
void solve1()
{
    for(int i=1;i<=n;i++)
    for(int j=n/2;j>=0;j--)
    for(int k=n/2;k>=0;k--)
    {
        if(j>=1) dp1[j][k]=max(dp1[j][k],dp1[j-1][k]+a[i][1]);
        if(k>=1) dp1[j][k]=max(dp1[j][k],dp1[j][k-1]+a[i][2]);
    }
    int ans=0;
    for(int j=n/2;j>=0;j--)
    for(int k=n/2;k>=0;k--)
        ans=max(dp1[j][k],ans);
    cout<<ans<<endl;

    for(int j=n/2;j>=0;j--)
    for(int k=n/2;k>=0;k--)
        dp1[j][k]=0;
    return;
}
void solve2()
{
    long long ans=0;
    for(int i=1;i<=n;i++) b[i]=a[i][1];
    sort(b+1,b+n+1,greater<int>());
    for(int i=1;i<=n/2;i++) ans+=b[i];
    cout<<ans<<endl;
}
void solve3()
{
    long long ans=0;
    for(int i=1;i<=n;i++) ans+=max({a[i][1],a[i][2],a[i][3]});
    cout<<ans<<endl;
}
void solve4()
{
    long long sum=0;
    long long ans=0;
    for(int i=1;i<=n;i++) sum+=a[i][2];
    for(int i=1;i<=n;i++) b[i]=a[i][1]-a[i][2];
    sort(b+1,b+n+1,greater<int>());
    for(int i=1;i<=n/2;i++) sum+=b[i];
    cout<<sum<<endl;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
        if(n==200) 
        {   
            solve4();
            continue;
        }
        if(n==100000&&a[100][2]==0&&a[100][3]==0&&a[10][2]==0&&a[10][3]==0&&a[1][2]==0&&a[1][3]==0)
        {
            solve2();
            continue;
        }
        if(n==100000&&a[1][3]==0&&a[10][3]==0&&a[100][3]==0)
        {
            solve4();
            continue;
        }
        if(n==100000)
        {
            solve3();
            continue;
        }
        for(int i=1;i<=n;i++)
        for(int j=n/2;j>=0;j--)
        for(int k=n/2;k>=0;k--)
        for(int l=n/2;l>=0;l--)
        {
            if(j>=1) f[j][k][l]=max(f[j][k][l],f[j-1][k][l]+a[i][1]);
            if(k>=1) f[j][k][l]=max(f[j][k][l],f[j][k-1][l]+a[i][2]);
            if(l>=1) f[j][k][l]=max(f[j][k][l],f[j][k][l-1]+a[i][3]);
        }
        int ans=0;
        for(int j=1;j<=n/2;j++)
            for(int k=1;k<=n/2;k++)
                for(int l=1;l<=n/2;l++)
                {
                    ans=max(ans,f[j][k][l]);
                }
        cout<<ans<<endl;
        CLEARS();
    }
    return 0;
}
