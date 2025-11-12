#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int sum=1;
    int a[101]={0};
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int b=a[1],c=b;
    int i=1;
    while(1)
    {
        b=max(b,a[i+1]);
        if(b!=c)
        {
            sum++;
            a[i+1]=0;
            b=c;
            i=1;
        }
        else i++;
        if(i==n*m)
        {
            break;
        }
    }
    double d=sum;
    long long j=ceil(d/n);
    if(j%2==1)
    {
        int k=sum%n;
        if(k==0)
        {
            k=n;
        }
        cout<<ceil(d/n)<<" "<<k;
    }
    else
    {
        int k=sum%n;
        cout<<ceil(d/n)<<" "<<k+1;
    }
    return 0;
}
