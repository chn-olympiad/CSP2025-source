#include<bits/stdc++.h>
using namespace std;
int n,once,once1=0;
long long ans=0;
vector<int> a;
vector<long long> b(1);
bool fun1()
{
    if(n<3) {
        cout<<0;
        return true;
    }else{
        long long all=0,ma=-1;
        for(int i=0;i<n;i++)
        {
            all+=a[i];
            if(a[i]>=ma) ma=a[i];
        }
        if(all>2*ma)
        {
            cout<<1;
            return true;
        }else{
            cout<<0;
            return true;
        }
    }
}
bool fun2()
{
    for(int i=3;i<=n;i++)
    {
        long long cheng=1,jia=1;
        for(int j=0;j<i;j++)
        {
            cheng*=n-j;
            jia*=j+1;
        }
        ans+=cheng/jia;
    }
    ans=ans%998244353;
    printf("%lld",ans);
    return true;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&once);
        a.push_back(once);
        if(once==1) once1++;
    }
    if(n<=3&&fun1()) return 0;
    if(once1==n&fun2()) return 0;
    sort(a.begin(),a.end());
    for(int i=1;i<=n;i++)
    {
        b.push_back(a[i-1]+b[i-1]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+2;j<=n;j++)
        {
            if(b[j]-b[i-1]>a[j-1]*2) ans++;
        }
    }
    printf("%lld",ans);
    return 0;
}
