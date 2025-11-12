#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
    int a,b,c;
}a[100010];
int t,n,dp1[205][205][205],dp2[10010][10010];
bool f1,f2;
void solution_1()
{
    memset(dp1,0,sizeof(dp1));
    //cout<<1<<' ';
    for(int i=1;i<=n;i++)
        for(int j=n/2;j>=0;j--)
            for(int k=n/2;k>=0;k--)
                for(int l=n/2;l>=0;l--)
                {

                        if(j>0)
                            dp1[j][k][l]=max(dp1[j][k][l],dp1[j-1][k][l]+a[i].a);
                        if(k>0)
                            dp1[j][k][l]=max(dp1[j][k][l],dp1[j][k-1][l]+a[i].b);
                        if(l>0)
                            dp1[j][k][l]=max(dp1[j][k][l],dp1[j][k][l-1]+a[i].c);
                }
        cout<<dp1[n/2][n/2][n/2];
}
bool cmp(node x,node y)
{
    return x.a>y.a;
}
void solution_2()
{
    //cout<<2<<' ';
    int res=0;
    for(int i=1;i<=n/2;i++)
        res+=a[i].a;
    cout<<res;
}
void solution_3()
{
    memset(dp2,0,sizeof(dp2));
    //cout<<3<<' ';
    for(int i=1;i<=n;i++)
        for(int j=n/2;j>=0;j--)
            for(int k=n/2;k>=0;k--)
                {
                    if(j>0)
                        dp2[j][k]=max(dp2[j][k],dp2[j-1][k]+a[i].a);
                    if(k>0)
                        dp2[j][k]=max(dp2[j][k],dp2[j][k-1]+a[i].b);
                }
    cout<<dp2[n/2][n/2];
}
void solution_4()
{
    //cout<<4<<' ';
    int ans=-99999999;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<>dis (1,3);
    for(int i=1;i<=100;i++)
    {
        int sum=0;
        for(int j=1;j<=n;j++)
        {
            int k=dis(gen);
            if(k==1)
                sum+=a[i].a;
            else if(k==2)
                sum+=a[i].b;
            else
                sum+=a[i].c;
        }
        ans=max(sum,ans);
    }
    cout<<ans;
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].a>>a[i].b>>a[i].c;
            if(a[i].c!=0)
                f1=f2=1;
            if(a[i].b!=0)
                f1=1;
        }
        if(n<=130)
            solution_1();
        else if(!f1)
            solution_2();
        else if(n<=10010&&!f2)
            solution_3();
        else
            solution_4();
        cout<<'\n';
    }
    return 0;
}
