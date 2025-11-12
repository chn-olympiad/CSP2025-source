#include<iostream>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m+10];
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int a0=a[1];
    for(int i=1;i<=n*m;i++)
    {
        for(int j=1;j<=n*m-i;j++)
        {
            if(a[j]<a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
    }
    int t=1;
    while(a[t]!=a0)
    {
        t++;
    }
    int k=t/n+1,s=(t-1)%n+1;
    if(k%2==0)
    {
        s=n-s+1;
    }
    cout<<k<<' '<<s;
    return 0;
}
