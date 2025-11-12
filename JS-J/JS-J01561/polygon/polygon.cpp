#include<bits/stdc++.h>
using namespace std;
int a[5007];
long long b[5007];
int cmp(int x,int y)
{

    return x>=y;
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
        b[0]=1;
        for(int i=1;i<=5000;i++)
            b[i]=b[i-1]*i;
    sort(a+1,a+n+1,cmp);
    if(n<3)cout<<0<<endl;
    if(n==3)
    {
        if(a[1]+a[2]+a[3]>2*a[1])cout<<1<<endl;
        else cout<<0<<endl;
    }
    else
    {
        int x=0;
    for(int i=3;i<=n;i++)
        x=(x+b[n]/b[i]/b[n-i])%998244353;
        cout<<x<<endl;
    }
   return 0;
}
