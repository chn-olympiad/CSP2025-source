#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int t,n,f[N][N],a[100005][5],b[100005];
int read()
{
    int sum=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
        sum=(sum<<3)+(sum<<1)+(c^48),c=getchar();
    return sum*f;
}
void solve1()
{
    //cout<<"aaa"<<endl;
    int ans=0;
    for(int i=1;i<=n;i++)
        b[i]=max(a[i][1],max(a[i][2],a[i][3]));
    sort(b+1,b+n+1);
    for(int i=n;i>=n/2+1;i--)
        ans+=b[i];
    cout<<ans<<endl;
}
void solve2()
{
    int ans=0;
    for(int i=1;i<=n;i++)
            for(int j=n/2;j>=0;j--)
                for(int k=n/2;k>=0;k--)
                {
                    if(i-j-k>=1) f[j][k]=f[j][k]+a[i][3];
                    if(j>=1) f[j][k]=max(f[j][k],f[j-1][k]+a[i][1]);
                    if(k>=1) f[j][k]=max(f[j][k],f[j][k-1]+a[i][2]);
                    if(i==n&&j+k>=n/2) ans=max(ans,f[j][k]);
                }
    cout<<ans<<endl;
}
void solve3()
{
    int ans=0;
    for(int i=1;i<=n;i++)
        ans+=max(max(a[i][1],a[i][2]),a[i][3]);
    cout<<ans<<endl;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    t=read();
    while(t--)
    {
        memset(f,0,sizeof(f));
        bool f1=1,f2=1,f3=1;
        n=read();
        for(int i=1;i<=n;i++)
        {
            a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
            if(a[i][1]!=0) f1=0;
            if(a[i][2]!=0) f2=0;
            if(a[i][3]!=0) f3=0;
        }
        if(f1+f2+f3>=2)
            solve1();
        else if(n<=2000)
            solve2();
        else
            solve3();
    }
    return 0;
}
