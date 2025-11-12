#include<bits/stdc++.h>
using namespace std;
long long a[1000002];
long long b[1000002];
long long turto(int n)
{
    long long ans=0;
    long long l[100002];
    int i=1;
    memset(l,0,sizeof(l));
    while(n!=0)
    {
        l[i]=n%2;
        n/=2;
        i++;
    }
    for(int j=i-1;j>=1;j--)
    {
        ans=ans*10+l[j];
    }
    return ans;
}
int solve(int n,int m)
{
    n=turto(n);
    m=turto(m);
    long long p[100002];
    long long d;
    long long lenn=0,lenm=0;
    memset(p,0,sizeof(p));
    int i=1;
    int n1=n,m1=m;
    while(n1)
    {
        lenn++;
        n1/=10;
    }
    while(m1)
    {
        lenm++;
        m1/=10;
    }
    while(n&&m)
    {
        if(n%10==m%10)
        {
            p[i]=0;
        }
        else
        {
            p[i]=1;
        }
        n/=10;
        m/=10;
        i++;
    }
    if(!n&&m)
    {
        p[i]=m%10;
        m/=10;
        i++;
    }
    else if(n&&!m)
    {
        p[i]=n%10;
        n/=10;
        i++;
    }
    for(int j=1;j<=i-1;j++)
    {
        d+=p[j]*pow(2,j-1);
    }
    return d;
}
int all(int a1,int b1)
{
    if(a1==b1)
    {
        return a[a1];
    }
    else{
        long long op=a[a1];
        for(int i=a1+1;i<=b1;i++)
        {
            op=solve(op,a[i]);
        }
        return op;
    }

}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    long long ans=0;
    cin>>n>>k;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=turto(a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(all(i,j)==k)
            {
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
