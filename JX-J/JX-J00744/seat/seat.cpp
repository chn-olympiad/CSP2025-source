#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
long long morthan=1;
long long atles=0;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++)
    {
        long long temp;
        cin>>temp;
        if(i==1)
        {
            atles=temp;
        }
        if(temp>atles)
        {
            morthan+=1;
        }
    }
    long long d_m,m_m;
    long long c,r;
    d_m=morthan/n;
    m_m=morthan%n;
    if(m_m==0)
    {
        c=d_m;
        if(d_m%2==1)
        {
            r=n;
        }
        else
        {
            r=1;
        }
    }
    else
    {
        c=d_m+1;
        if(c%2==1)
        {
            r=m_m;
        }
        else
        {
            r=n-m_m+1;
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
