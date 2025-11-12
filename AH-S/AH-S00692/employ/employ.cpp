#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
long long b[1000000];
long long c[1000000];
long long sum=0;
long long n,m;
long long why(long long x,long long y)
{
    if(x==0)
    {
        return sum;
    }
    for(long long i=1;i<=x;i++)
    {
        if(i!=y)
        {
            c[x]=b[i];
            why(x-1,i);
            if(x)
            {
                long long ss=0;
                long long sss=0;
                for(long long i=1;i<=n;i++)
                {
                    if(c[i]<=ss)
                    {
                        ss++;
                    }
                    else
                    {
                        if(a[i]==0)
                        {
                            ss++;
                        }
                        else
                        {
                            sss++;
                        }
                    }
                }
                if(sss>=m)
                {
                    sum++;
                }
            }
        }
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    string s;
    cin>>n>>m;
    cin>>s;
    for(long long i=1;i<=n;i++)
    {
        cin>>b[i];
        if(s[i-1]=='0')
        {
            a[i]=0;
        }
        else
        {
            a[i]=1;
        }
    }
    cout<<why(n,0)%998244353;
    return 0;
}
