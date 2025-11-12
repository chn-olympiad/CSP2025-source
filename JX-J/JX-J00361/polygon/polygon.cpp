#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10,mod=998244353;
int jie[N],inv[N],a[N],n,qz[N];
int qmi(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
int A(int x,int y)
{
    return jie[x]*inv[x-y]%mod;
}
int C(int x,int y)
{
    return inv[y]*A(x,y)%mod;
}
signed main()
{
    jie[0]=1,inv[0]=1;
    for(int i=1;i<=5000;i++)
    {
        jie[i]=jie[i-1]*i%mod;
    }
    inv[5000]=qmi(jie[5000],mod-2);
    for(int i=4999;i>=1;i--)
    {
        inv[i]=inv[i+1]*(i+1)%mod;
    }
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int ans=0;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        qz[i]=qz[i-1]+a[i];
    }
    for(int i=3;i<=n;i++)
    {
        ans=(ans+C(n,i))%mod;
    }
    for(int i=n;i>=1;i--)
    {
       int back=-1,back1=-1,back2=0;
       for(int j=2;j<=i;j++)
       {
           if(qz[j]+a[i]<=2*a[i])
           {
               back=j;
           }
           else
           {
               for(int o=1;o<=j;o++)
               {
                   if(qz[j]+a[i]-qz[o]<=2*a[i]&&j+1-o>=3)
                   {
                       back2=j+1-o;
                       back1=j;
                   }
               }
           }
       }
       if(back!=-1)
       {
           for(int j=2;j<=back;j++)
           {
               ans=(ans-C(back,j))%mod;
           }
       }
       if(back1!=-1)
       {
           ans=(ans-C(back1,back2))%mod;
       }
    }
    cout<<(ans+mod)%mod<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
