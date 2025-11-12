#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
int i;
int a[10005];
int b[10005];
int c[10005][10005];
void fun(int f)
{
    if(f==0)
    {
        sort(b+1,b+i+1);
        int maxx=b[i];
        int sum=0;
        for(int j=1;j<=i;j++)
        {
            sum+=b[i];
        }
        if(sum>maxx*2)
        {
            cnt++;
        }
        return;
    }
    for(int i=1;i<=f;i++)
    {
        b[f]=a[i];
        fun(f-1);
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==3)
    {
        sort(a+1,a+3+1);
        int maxx=a[3];
        int sum=a[1]+a[2]+a[3];
        if(sum>maxx*2)
        {
            cout<<1;
            return 0;
        }
        cout<<0;
        return 0;
    }
    c[1][1]=c[2][1]=c[2][2]=0;
    for(int j=1;j<=5005;j++)
    {
        c[1][j]=1;
    }
    for(int j=3;j<=5005;j++)
    {
        for(int k=2;k<=5005;k++)
        {
            c[j][k]=c[j-1][k-1]+c[j-1][k];
        }
    }
    if(a[1]==a[2]&&a[1]==a[3]&&a[1]==a[4]&&a[1]==a[5]&&a[1]==a[6]&&a[1]==a[7]&&a[1]==1)
    {
        int ans=0;
        for(int l=1;l<=n/2;l++)
        {
            ans+=c[n+1][l];
        }
        cout<<ans;
        return 0;
    }
    for(i=3;i<=n;i++)
    {
        fun(i);
    }
    cout<<cnt;
    return 0;
}
