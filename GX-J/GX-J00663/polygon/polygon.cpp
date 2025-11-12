#include<bits/stdc++.h>
using namespace std;

int wei(int a)
{
    int w=0;
    while(a>0)
    {
        a/=2;
        w++;
    }
    return w;
}

int main ()
{
    freopen("polygon1.in","r",stdin);
    freopen("polygon1.out","w",stdout);

    long long n,jie=0;
    cin>>n;
    long long num[n];

    for(long long i=0;i<n;i++)
        cin>>num[i];

    sort(num,num+n);

    int a=7;
    while(wei(a)<=n)
    {
        int b=a;
        int x[1024];
        int i;
        for(i=0;b>0;i++)
        {
            x[i]=b%2;
            b/=2;
        }
        long long m=0,zhong=0;
        for(int j=0;j<=i;j++)
        {
            if(x[j])
            {
                m=max(m,num[j]);
                zhong+=num[j];
            }
        }

        if(zhong>m*2)
        {
            jie++;
        }
        a++;
    }

    if((jie/2)%2==0)
        cout<<jie/2+3;
    else
        cout<<jie/2+1;

    return 0;
}
