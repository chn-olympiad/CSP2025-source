#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005],p[9]={1,2,4,8,16,32,64,128,256},cnt=0;
bool c[500005]={0};
long long yihuo(long long x,long long y)//yihuo(<=256)
{
    long long x1,y1,x2=x,y2=y,xx[9]={0},yy[9]={0},zz[9]={0},z=0,i=8;
    while(x2!=0)
    {
        x1=x1*10+x2%2;
        xx[i]=x2%2;
        i--;
        x2/=2;
    }
    i=8;
    while(y2!=0)
    {
        y1=y1*10+y2%2;
        yy[i]=y2%2;
        i--;
        y2/=2;
    }
    for(long long j=8;j>=1;j--)
    {
        if(xx[j]!=yy[j])
        {
            zz[j]=1;
        }
    }
    for(long long j=1;j<=8;j++)
    {
        z=z*10+zz[j];
    }
    long long z1=0,k=0;
    while(z!=0)
    {
        z1+=p[k]*z%10;
        z/=10;
        k++;
    }
    return z1;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin>>n>>k;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++)//the length of (a,b)
    {
        for(long long j=1;j<=n-i+1;j++)//the start
        {
            bool flag=1;
            for(long long k=j;k<=j+i-1;k++)
            {
                if(c[k]==1)
                {
                    flag=0;break;
                }
            }
            if(flag==0)
            {
                continue;
            }
            else
            {
                long long he=0;
                for(long long k=j;k<=j+i-1;k++)
                {
                    he=yihuo(he,a[k]);
                }
                if(he==k)
                {
                    cnt++;
                    for(long long k=j;k<=j+i-1;k++)
                    {
                        c[k]=1;
                    }
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}
