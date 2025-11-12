#include <bits/stdc++.h>
using namespace std;
long long c1[1000000];
long long c2[1000000];
long long c3[1000000];
long long c[1000000];
long long a[4];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t;
    cin>>t;
    for(long long i=1;i<=t;i++)
    {
        long long n,s=0;
        cin>>n;
        for(long long i=1;i<=n;i++)
        {
            cin>>c1[i]>>c2[i]>>c3[i];
            if(c1[i]>c2[i]&&c1[i]>c3[i])
            {
                s+=c1[i];
                c[i]=1;
                a[1]++;
            }
            else if(c2[i]>c1[i]&&c2[i]>c3[i])
            {
                s+=c2[i];
                c[i]=2;
                a[2]++;
            }
            else if(c3[i]>c1[i]&&c3[i]>c2[i])
            {
                s+=c3[i];
                c[i]=3;
                a[3]++;
            }
            else if(c1[i]==c2[i]&&c1[i]!=c3[i])
            {
                if(c[1]>c[2])
                {
                    s+=c2[i];
                    c[i]=2;
                    c[2]++;
                }
                else
                {
                    s+=c1[i];
                    c[i]=1;
                    c[1]++;
                }
            }
            else if(c1[i]==c3[i]&&c1[i]!=c2[i])
            {
                if(c[1]>c[3])
                {
                    s+=c3[i];
                    c[i]=3;
                    c[3]++;
                }
                else
                {
                    s+=c1[i];
                    c[i]=1;
                    c[1]++;
                }
            }
            else if(c2[i]==c3[i]&&c1[i]!=c2[i])
            {
                if(c[2]>c[3])
                {
                    s+=c3[i];
                    c[i]=3;
                    c[3]++;
                }
                else
                {
                    s+=c2[i];
                    c[i]=2;
                    c[2]++;
                }
            }
            long long xiao=20001;
            long long sum;
            if(a[1]>n/2)
            {
                for(long long i=1;i<=n;i++)
                {
                    if(c[i]!=0)
                    {
                        if(xiao>=c1[i])
                        {
                            xiao=c1[i];
                            sum=i;
                        }
                    }
                }
                if(a[2]==n)
                {
                    a[3]++;
                    c[i]=3;
                    s-=c1[sum];
                    s+=c3[sum];
                }
                else if(a[3]==n)
                {
                    a[2]++;
                    c[i]=2;
                    s-=c1[sum];
                    s+=c2[sum];
                }
                else if(c2[sum]>c3[sum])
                {
                    a[2]++;
                    c[i]=2;
                    s-=c1[sum];
                    s+=c2[sum];
                }
                else if(c2[sum]<c3[sum])
                {
                    a[3]++;
                    c[i]=3;
                    s-=c1[sum];
                    s+=c3[sum];
                }
                else if(c2[sum]==c3[sum])
                {
                    if(a[2]>a[3])
                    {
                        a[3]++;
                        c[i]=3;
                        s-=c1[sum];
                        s+=c3[sum];
                    }
                    else
                    {
                        a[2]++;
                        c[i]=2;
                        s-=c1[sum];
                        s+=c2[sum];
                    }
                }
            }
            if(a[1]>n/2)
            {
                for(long long i=1;i<=n;i++)
                {
                    if(c[i]!=0)
                    {
                        if(xiao>=c1[i])
                        {
                            xiao=c1[i];
                            sum=i;
                        }
                    }
                }
                if(a[2]==n)
                {
                    a[3]++;
                    c[i]=3;
                    s-=c1[sum];
                    s+=c3[sum];
                }
                else if(a[3]==n)
                {
                    a[2]++;
                    c[i]=2;
                    s-=c1[sum];
                    s+=c2[sum];
                }
                else if(c2[sum]>c3[sum])
                {
                    a[2]++;
                    c[i]=2;
                    s-=c1[sum];
                    s+=c2[sum];
                }
                else if(c2[sum]<c3[sum])
                {
                    a[3]++;
                    c[i]=3;
                    s-=c1[sum];
                    s+=c3[sum];
                }
                else if(c2[sum]==c3[sum])
                {
                    if(a[2]>a[3])
                    {
                        a[3]++;
                        c[i]=3;
                        s-=c1[sum];
                        s+=c3[sum];
                    }
                    else
                    {
                        a[2]++;
                        c[i]=2;
                        s-=c1[sum];
                        s+=c2[sum];
                    }
                }
            }
            if(a[2]>n/2)
            {
                for(long long i=1;i<=n;i++)
                {
                    if(c[i]!=0)
                    {
                        if(xiao>=c2[i])
                        {
                            xiao=c2[i];
                            sum=i;
                        }
                    }
                }
                if(a[1]==n)
                {
                    a[3]++;
                    c[i]=3;
                    s-=c2[sum];
                    s+=c3[sum];
                }
                else if(a[3]==n)
                {
                    a[1]++;
                    c[i]=1;
                    s-=c2[sum];
                    s+=c1[sum];
                }
                else if(c1[sum]>c3[sum])
                {
                    a[1]++;
                    c[i]=1;
                    s-=c2[sum];
                    s+=c1[sum];
                }
                else if(c1[sum]<c3[sum])
                {
                    a[3]++;
                    c[i]=3;
                    s-=c2[sum];
                    s+=c3[sum];
                }
                else if(c1[sum]==c3[sum])
                {
                    if(a[1]>a[3])
                    {
                        a[3]++;
                        c[i]=3;
                        s-=c2[sum];
                        s+=c3[sum];
                    }
                    else
                    {
                        a[1]++;
                        c[i]=1;
                        s-=c2[sum];
                        s+=c1[sum];
                    }
                }
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
