#include<iostream>
#include<cmath>
using namespace std;
int a[22],b[22],c[25];
long long na,nb,nc,t10a,t10b,t10c,n,k;
long long number[500005];
void clean()
{
    for(int i=0;i<22;i++)
    {
        a[i]=0;
        b[i]=0;
    }
}
void za(long long t)
{
    na=0;
    while(t!=0)
    {
        a[na++]=t%2;
        t/=2;
    }
}
void zb(long long t)
{
    nb=0;
    while(t!=0)
    {
        b[nb++]=t%2;
        t/=2;
    }
}
void zc()
{
    t10c=0;
    for(int i=0;i<nc;i++)
    {
        t10c+=pow(2,i)*c[i];
    }
}
void z()
{
    nc=max(na,nb);
    for(int i=0;i<nc;i++)
    {
        c[i]=!((a[i]&b[i])|((!a[i])&&(!b[i])));
    }
}
void t(long long a,long long b)
{
    clean();
    za(t10a);
    zb(t10b);
    z();
    zc();
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>number[i];
    }
    int sum=0;
    if(k==0)
    {
        for(int i=0;i<n;i++)
        {
            if(number[i]==0)sum++;
        }
        cout<<sum;
        return 0;
    }
    for(int i=0;i<n;)
    {

        long long p=i,r=0;
        while(r<k)
        {
            t10a=r,t10b=number[i];
            t(r,number[i]);
            r=t10c;
            i++;
        }
        if(r==k)sum++;
        else i=p+1;
        //cout<<i<<' ';
    }
    cout<<sum;
    return 0;
}
